#include "../include/Action.h"
#include "../include/Studio.h"

extern Studio* backup;

//-----BaseAction-----

BaseAction::BaseAction(): errorMsg("Generic error"), status(ERROR) {}

BaseAction::BaseAction(std::string str, ActionStatus actionStatus): errorMsg(str), status(actionStatus) {}

BaseAction::~BaseAction(){};


ActionStatus BaseAction::getStatus() const {
    return status;
}

void BaseAction::complete() {
    status=COMPLETED;
}

void BaseAction::error(std::string errorMsg) {
    status=ERROR;
    std::cout << "Error: " << getErrorMsg() << std::endl;
    //push to logAction
}

std::string BaseAction::getErrorMsg() const {
    return errorMsg;
}


//------OpenTrainer------
OpenTrainer::OpenTrainer(int id, std::vector<Customer *> &customersList):
        BaseAction("Trainer does not exist or is already open", ERROR),
        trainerId(id), customers(customersList), str("") {}

OpenTrainer::~OpenTrainer() {}

OpenTrainer* OpenTrainer::clone(){
    return new OpenTrainer(*this);
}

std::string OpenTrainer::getStr () const{
    return str;
}

void OpenTrainer::addStr(std::string toAdd)  {
    str+=toAdd;
}

void OpenTrainer::act(Studio& studio) {

    for (std::size_t i = 0; i < customers.size(); i++) {
        std::string name = customers[i]->getName();
        std::string type = customers[i]->getType();
        std::string theString = " " + name + "," + type;
        addStr(theString);
    }

    if (studio.getTrainer(trainerId)== nullptr || studio.getTrainer(trainerId)->isOpen()) {
        error(getErrorMsg());
    }
    else {
        studio.getTrainer(trainerId)->openTrainer();
        int trainerCapacity = studio.getTrainer(trainerId)->getCapacity();
        int numOfCustomers = customers.size();
        for (int i = 0; i<trainerCapacity && i < numOfCustomers; i++) {
            studio.getTrainer(trainerId)->addCustomer(customers[i]);
        }
        complete();
    }
}

std::string OpenTrainer::toString() const {
    std::string output = "open "+to_string(trainerId);
    output+=getStr();
    if(this->getStatus()==COMPLETED) {
        output+=" Completed";
    }
    else {
        output+=" Error: "+this->getErrorMsg();
    }
    return output;
}


//------Order------
Order::Order(int id):
    BaseAction("Trainer does not exist or is not open", ERROR),
    trainerId(id) {}

Order::~Order(){}

Order* Order::clone() {
    return new Order(*this);
}

void Order::act(Studio &studio) {
    if (studio.getTrainer(trainerId) == nullptr || !studio.getTrainer(trainerId)->isOpen()) {
        error(getErrorMsg());
    }
    else {
        Trainer *trainer = studio.getTrainer(trainerId);
        if (!studio.getTrainer(trainerId)->getWasOrdered()) {
            int numOfCustomers = studio.getTrainer(trainerId)->getCustomers().size();
            std::vector<Customer *> &customersList = studio.getTrainer(trainerId)->getCustomers();
            std::vector<Workout> &workoutOptions = studio.getWorkoutOptions();
            for (int i = 0; i < numOfCustomers; i++) {
                std::vector<int> workoutIDs = customersList[i]->order(workoutOptions);
                trainer->order(customersList[i]->getId(), workoutIDs, workoutOptions);
            }
        }
        //print the orders
        std::vector<OrderPair> &orderList = trainer->getOrders();
        for (std::size_t i = 0; i < orderList.size(); i++) {
            //find name
            int id = orderList[i].first;
            std::string name = trainer->getCustomer(id)->getName();
            //find workout
            std::string workoutName = orderList[i].second.getName();
            std::cout << name << " Is Doing " << workoutName << endl;
        }
        trainer->setWasOrdered(true);
        complete();
    }

}

std::string Order::toString() const {
    std::string output = "order "+to_string(trainerId)+" ";
    if(this->getStatus()==COMPLETED) {
        output+="Completed";
    }
    else {
        output+="Error: "+getErrorMsg();
    }
    return output;
}


//------MoveCustomer------
MoveCustomer::MoveCustomer(int src, int dst, int customerId) :
        BaseAction("Cannot move customer", ERROR),
        srcTrainer(src), dstTrainer(dst), id(customerId){}

MoveCustomer::~MoveCustomer() {}

MoveCustomer* MoveCustomer::clone() {
    return new MoveCustomer(*this);
}

void MoveCustomer::act(Studio &studio){
    if(srcTrainer!=dstTrainer) {
        if (studio.getTrainer(srcTrainer) == nullptr || studio.getTrainer(dstTrainer) == nullptr ||
            studio.getTrainer(srcTrainer)->getCustomer(id) == nullptr) {
                error(getErrorMsg());
        } else if (!studio.getTrainer(srcTrainer)->isOpen() || !studio.getTrainer(dstTrainer)->isOpen()) {
                error(getErrorMsg());
        } else if (studio.getTrainer(dstTrainer)->getCapacity() == (int)studio.getTrainer(dstTrainer)->getCustomers().size()) {
                error(getErrorMsg());
        } else {
                Customer *temp = studio.getTrainer(srcTrainer)->getCustomer(id);
                studio.getTrainer(srcTrainer)->removeCustomer(id);
                studio.getTrainer(dstTrainer)->addExistCustomer(temp);
                std::vector<int> tempOrder = temp->order(studio.getWorkoutOptions());
                studio.getTrainer(dstTrainer)->addExistOrder(id, tempOrder, studio.getWorkoutOptions());

                if ((int)studio.getTrainer(srcTrainer)->getCustomers().size() == 0) {
                    Close* close = new Close(srcTrainer);
                    close->act(studio);
                    delete close;
                }
                temp = nullptr;
                complete();
            }
        }
}
 std::string MoveCustomer::toString() const{
    std::string output = "move "+to_string(srcTrainer)+" "+to_string(dstTrainer)+" "+to_string(id)+" ";
    if(this->getStatus()==COMPLETED) {
        output+="Completed";
    }
    else {
        output+="Error: "+getErrorMsg();
    }
    return output;
}


//------Close------
Close::Close(int id) :
    BaseAction("Trainer does not exist or is not open", ERROR),
    trainerId(id) {}

Close::~Close(){}

Close* Close::clone() {
    return new Close(*this);
}


void Close::act(Studio &studio) {
    if (studio.getTrainer(trainerId)==nullptr || !studio.getTrainer(trainerId)->isOpen()) {
        error(getErrorMsg());
    }
    else {
        Trainer *trainer = studio.getTrainer(trainerId);
        trainer->updateSalary();
        trainer->closeTrainer();
        cout << "Trainer " << trainerId << " closed. Salary " << trainer->getSalary() << "NIS" << endl;
        complete();
    }
}


std::string Close::toString() const {
    std::string output = "close "+to_string(trainerId)+" ";
    if(this->getStatus()==COMPLETED) {
        output+="Completed";
    }
    else {
        output+="Error: "+getErrorMsg();
    }
    return output;
}


//------CloseAll------
CloseAll::CloseAll():
        BaseAction("", ERROR){}

CloseAll::~CloseAll() {}

CloseAll* CloseAll::clone(){
    return new CloseAll(*this);
}


void CloseAll::act(Studio &studio) {
    int numOfTrainers = studio.getNumOfTrainers();
    for (int i = 0; i < numOfTrainers; ++i) {
        if(studio.getTrainer(i)->isOpen()){
            Close* close = new Close(i);
            close->act(studio);
            delete close;
        }
    }
    studio.closeStudio();
    complete();
}

std::string CloseAll::toString() const {
    return "closeall";
}

//------PrintWorkoutOptions------
PrintWorkoutOptions::PrintWorkoutOptions(): BaseAction("", ERROR){}

PrintWorkoutOptions::~PrintWorkoutOptions() {}

PrintWorkoutOptions* PrintWorkoutOptions::clone() {
    return new PrintWorkoutOptions(*this);
}

void PrintWorkoutOptions::act(Studio &studio) {
    std::vector <Workout>& workoutOptions = studio.getWorkoutOptions();
    for(std::size_t i=0; i<workoutOptions.size(); i++) {
        std::string name = workoutOptions[i].getName();
        std::string type = workoutOptions[i].toString();
        int price = workoutOptions[i].getPrice();
        std::cout << name << ", " << type << ", " << price << endl;
    }
    complete();
}

std::string PrintWorkoutOptions::toString() const {
    return "workout_options";
}

//------PrintTrainerStatus------
PrintTrainerStatus::PrintTrainerStatus(int id):
        BaseAction("", ERROR), trainerId(id){}

PrintTrainerStatus::~PrintTrainerStatus() {}

PrintTrainerStatus* PrintTrainerStatus::clone() {
    return new PrintTrainerStatus(*this);
}


void PrintTrainerStatus::act(Studio &studio) {
    if (studio.getTrainer(trainerId)!=nullptr) {
        if(!studio.getTrainer(trainerId)->isOpen()) {
            if (studio.getTrainer(trainerId)->getIsEverOpened()) {
                cout << "Trainer " << trainerId << " status: closed" << endl;
            }
        }
        else {
            cout << "Trainer " << trainerId << " status: open" << endl;
            cout << "Customers:" << endl;
            std::vector <Customer*> customers = studio.getTrainer(trainerId)->getCustomers();
            for (std::size_t i=0; i<customers.size(); i++) {
                std::cout << customers[i]->getId() << " " << customers[i]->getName() << endl;
            }
            cout << "Orders:" << endl;
            std::vector<OrderPair> orderList = studio.getTrainer(trainerId)->getOrders();
            int salary = studio.getTrainer(trainerId)->getSalary();
            for (std::size_t i=0; i<orderList.size(); i++) {
                std::cout << orderList[i].second.getName() << " " << orderList[i].second.getPrice() << "NIS " << orderList[i].first << endl;
                salary+=orderList[i].second.getPrice();
            }
            cout << "Current Trainer's Salary: " << salary << "NIS" << endl;
        }
    }
    complete();
}

std::string PrintTrainerStatus::toString() const {
    std::string output = "status "+to_string(trainerId)+" ";
    if(this->getStatus()==COMPLETED) {
        output+="Completed";
    }
    else {
        output+="Error: "+getErrorMsg();
    }
    return output;
}
//------PrintActionsLog------
PrintActionsLog::PrintActionsLog():
        BaseAction("", ERROR){}

PrintActionsLog::~PrintActionsLog() {}

PrintActionsLog* PrintActionsLog::clone() {
    return new PrintActionsLog(*this);
}


void PrintActionsLog::act(Studio &studio) {
    std::vector<BaseAction*> actionsLog = studio.getActionsLog();
    for(std::size_t i=0; i<actionsLog.size(); i++) {
        std::cout << actionsLog[i]->toString() << endl;
    }
}

std::string PrintActionsLog::toString() const {
    return "log";
}

//------BackupStudio------
BackupStudio::BackupStudio():
        BaseAction("", ERROR){}

BackupStudio::~BackupStudio() {}

BackupStudio* BackupStudio::clone() {
    return new BackupStudio(*this);
}

void BackupStudio::act(Studio &studio) {
    if(!studio.getIsBackedup()){
        backup = new Studio(studio);
        studio.setBackup();
    }
    else {
        *backup = studio;
    }
}

std::string BackupStudio::toString() const {
    return "backup";
}

//------RestoreStudio------

RestoreStudio::RestoreStudio():
        BaseAction("No backup available", ERROR){}

RestoreStudio::~RestoreStudio() {}

RestoreStudio* RestoreStudio::clone() {
    return new RestoreStudio(*this);
}

void RestoreStudio::act(Studio &studio) {
    if(!studio.getIsBackedup()) {
        error(getErrorMsg());
    }
    else {
        studio = *backup;
        studio.setBackup();
        complete();
    }
}

std::string RestoreStudio::toString() const {
    std::string output = "restore ";
    if(this->getStatus()==COMPLETED) {
        output+="Completed";
    }
    else {
        output+="Error: "+getErrorMsg();
    }
    return output;
}



