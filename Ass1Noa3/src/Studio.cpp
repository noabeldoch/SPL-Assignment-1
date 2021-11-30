
#include "../include/Studio.h"


Studio::Studio(): open(false), isBackedup(false), newCustomerId(0) {}

Studio::Studio(const std::string &configFilePath): open(false), isBackedup(false), newCustomerId(0) {
    std::ifstream file(configFilePath);
    char line[500];
    int action = 0;
    int workoutId = 0;

    while (file) {
        file.getline(line, 500);
        if (line[0] == '#')
            continue;
        if (line[0] == '\0')
            continue;
        if (action == 0) {//create Trainers
            action++;
        }
        else if (action==1) { //create trainers define capacity for each trainer
            defineTrainersCapacity(line);
            action++;
        }
        else {
            workoutOptions workoutOption = extractWordFromString(line);
            Workout workout (workoutId, workoutOption.name, workoutOption.price, workoutOption.type);
            workout_options.push_back(workout);
            workoutId++;
        }
    }
}


Studio::~Studio(){
    for(std::size_t i=0 ; i<trainers.size() ; i++){
        delete trainers[i];
        trainers[i]=nullptr;
    }
    trainers.clear();

    for(std::size_t i=0 ; i<actionsLog.size() ; i++){
        delete actionsLog[i];
    }
    actionsLog.clear();
}


Studio::Studio(const Studio& other): open(other.open), isBackedup(other.isBackedup), newCustomerId(other.newCustomerId){
    for(size_t i=0; i<other.trainers.size(); i++) {
        Trainer* trainer = new Trainer(*other.trainers[i]);
        this->trainers.push_back(trainer);
    }

    for(size_t i=0; i<other.workout_options.size(); i++) {
        Workout workout = other.workout_options[i];
        this->workout_options.push_back(workout);
    }

    for(size_t i=0; i<other.actionsLog.size(); i++) {
        BaseAction* action = other.actionsLog[i]->clone();
        this->actionsLog.push_back(action);
    }
}


Studio& Studio::operator=(const Studio& other){
    if (this!=&other) {
        this->open = other.open;
        this->isBackedup = other.isBackedup;
        this->newCustomerId = other.newCustomerId;

        for(std::size_t i=0; i<trainers.size(); i++) {
            delete trainers[i];
        }
        trainers.clear();
        workout_options.clear();
        for(std::size_t i=0; i<actionsLog.size(); i++) {
            delete actionsLog[i];
        }
        actionsLog.clear();

        for(size_t i=0; i<other.trainers.size(); i++) {
            Trainer* trainer = new Trainer(*other.trainers[i]);
            this->trainers.push_back(trainer);
        }

        for(size_t i=0; i<other.workout_options.size(); i++) {
            Workout workout = other.workout_options[i];
            this->workout_options.push_back(workout);
        }

        for(size_t i=0; i<other.actionsLog.size(); i++) {
            BaseAction* baseAction = other.actionsLog[i]->clone();
            actionsLog.push_back(baseAction);
        }
    }
    return *this;
}

Studio::Studio(Studio&& other): open(other.open), isBackedup(other.isBackedup), newCustomerId(other.newCustomerId){
    clear();
    for(std::size_t i=0; i<other.workout_options.size(); i++){
        this->workout_options.push_back(other.workout_options[i]);
    }
   other.workout_options.clear();

   for(std::size_t i=0; i<other.trainers.size(); i++) {
       this->trainers.push_back(other.trainers[i]);
   }
   other.trainers.clear();

    for(std::size_t i=0; i<other.actionsLog.size(); i++) {
        this->actionsLog.push_back(other.actionsLog[i]);
    }
    other.actionsLog.clear();
}


Studio& Studio::operator=(Studio&& other){
    if(this!=&other) {
        clear();
        open=other.open;
        isBackedup=other.isBackedup;
        newCustomerId=other.newCustomerId;

        for(std::size_t i=0; i<other.workout_options.size(); i++){
            this->workout_options.push_back(other.workout_options[i]);
        }
        other.workout_options.clear();

        for(std::size_t i=0; i<other.trainers.size(); i++) {
            this->trainers.push_back(other.trainers[i]);
        }
        other.trainers.clear();

        for(std::size_t i=0; i<other.actionsLog.size(); i++) {
            this->actionsLog.push_back(other.actionsLog[i]);
        }
        other.actionsLog.clear();
    }
    return *this;
}

void Studio::clear() {
    for(std::size_t i=0; i<trainers.size(); i++) {
        delete trainers[i];
    }
    trainers.clear();
    workout_options.clear();
    for(std::size_t i=0; i<actionsLog.size(); i++) {
        delete actionsLog[i];
    }
    actionsLog.clear();
}


void Studio::start() {
    open = true;
    cout << "Studio is now open!" << endl;

    std::string action;
    getline(cin,action);
    std::vector<std::string> actionVector = actionToString(action);
    if(actionVector.size()==0) {
        actionVector.push_back("");
    }

    while (actionVector[0].compare("closeall") != 0) {

        if(actionVector[0].compare("open")==0){
            int id = stoi(actionVector[1]);
            std::vector<Customer*> customers;
            for(std::size_t i=2 ; i<actionVector.size() ; i+=2){
                std::string name = actionVector[i];
                if(actionVector[i+1].compare("swt")==0){
                    SweatyCustomer* swt = new SweatyCustomer(name, getNewCustomerId());
                    setNewCustomerId();
                    customers.push_back(swt);
                }
                else if(actionVector[i+1].compare("chp")==0){
                    CheapCustomer* chp = new CheapCustomer(name, getNewCustomerId());
                    setNewCustomerId();
                    customers.push_back(chp);
                }
                else if(actionVector[i+1].compare("mcl")==0){
                    HeavyMuscleCustomer* mcl = new HeavyMuscleCustomer(name, getNewCustomerId());
                    setNewCustomerId();
                    customers.push_back(mcl);
                }
                else if(actionVector[i+1].compare("fbd")==0){
                    FullBodyCustomer* fbd = new FullBodyCustomer(name, getNewCustomerId());
                    setNewCustomerId();
                    customers.push_back(fbd);
                }
            }

            BaseAction* open = new OpenTrainer(id, customers);
            open->act(*this);
            actionsLog.push_back(open);
            if (open->getStatus()==ERROR){
                for(std::size_t i=0; i<customers.size() ; i++){
                    delete customers[i];
                    decreseNewCustomerId();
                }
                customers.clear();
            }

            else if(getTrainer(id)->getCapacity()<(int)customers.size()) {
                for (std::size_t i=getTrainer(id)->getCapacity(); i<customers.size(); i++) {
                     delete customers[i];
                     decreseNewCustomerId();
                }
            }
        }

        else if(actionVector[0].compare("order")==0){
            int id = stoi(actionVector[1]);
            BaseAction* order = new Order(id);
            order->act(*this);
            actionsLog.push_back(order);
        }

        else if(actionVector[0].compare("move")==0){
            int srcId = stoi(actionVector[1]);
            int dstId = stoi(actionVector[2]);
            int customerId = stoi(actionVector[3]);
            BaseAction* move = new MoveCustomer(srcId,dstId,customerId);
            move->act(*this);
            actionsLog.push_back(move);
        }

        else if(actionVector[0].compare("close")==0){
            int trainerId = stoi(actionVector[1]);
            BaseAction* close = new Close(trainerId);
            close->act(*this);
            actionsLog.push_back(close);
        }

        else if(actionVector[0].compare("workout_options")==0){
            BaseAction* printWorkouts = new PrintWorkoutOptions();
            printWorkouts->act(*this);
            actionsLog.push_back(printWorkouts);
        }

        else if(actionVector[0].compare("status")==0){
            int trainerId = stoi(actionVector[1]);
            BaseAction* printStatus = new PrintTrainerStatus(trainerId);
            printStatus->act(*this);
            actionsLog.push_back(printStatus);
        }

        else if(actionVector[0].compare("log")==0){
            BaseAction* printActions = new PrintActionsLog();
            printActions->act(*this);
            actionsLog.push_back(printActions);
        }

        else if(actionVector[0].compare("backup")==0) {
            BaseAction* newBackup = new BackupStudio();
            newBackup->act(*this);
            actionsLog.push_back(newBackup);
        }

        else if (actionVector[0].compare("restore")==0){
            BaseAction* restore = new RestoreStudio();
            restore->act(*this);
            actionsLog.push_back(restore);
        }

        actionVector.clear();
        getline(cin,action);
        actionVector = actionToString(action);
        if(actionVector.size()==0) {
            actionVector.push_back("");
        }
    }
}

std::vector<std::string> Studio::actionToString(std::string action){
    std::size_t i = 0;
    string currString="";
    std::vector<std::string> output;
    while(i<action.length()) {
        if(action.at(i)==' ' || action.at(i)==','){
            if (currString.compare("")!=0) {
                output.push_back(currString);
            }
            currString="";
        }
        else {
            currString+=action.at(i);
        }
        i++;
    }
    if (currString.compare("")!=0) {
        output.push_back(currString);
    }
    return output;
}


int Studio::convertTextToNumber(char *line) {
    int i = 0;
    int num = 0;
    while (line[i] != '\0') {
        if (line[i] == '\r') {
            i++;
            continue;
        }
        num = num * 10 + (int) line[i] - 48;
        i++;
    }
    return num;
}

void Studio::defineTrainersCapacity(char* line) {
    int i = 0;
    int j = 0;
    char arr[100];
    int capacity;
    while (line[i] != '\0') {
        if (line[i] == ',' || line[i] == ' ' ||line[i]=='\r') {
            arr[j] = '\0';
            capacity = convertTextToNumber(arr);
            Trainer* t = new Trainer(capacity);
            trainers.push_back(t);
            i++;
            j = 0;
        }
        else {
            arr[j] = line[i];
            i++;
            j++;
        }
    }
}

Studio::workoutOptions Studio::extractWordFromString(char* line) {
    int i=0;
    int wordNum = 0;
    workoutOptions curr;
    std::string temp = "";
    while (line[i] != '\0') {
        if(line[i]!=' ') {
            if (line[i] != ',') {
                temp = temp + line[i];
            } else {
                switch (wordNum) {
                    case 0: {
                        curr.name = temp;
                        temp = "";
                        break;
                    }
                    case 1: {
                        curr.type = defineWorkoutType(temp);
                        temp = "";
                        break;
                    }
                }
                wordNum++;
            }
        }
        i++;
    }
    char chArr[temp.length()+1];
    for (std::size_t i=0; i<temp.length(); i++)
        chArr[i]=temp.at(i);
    chArr[temp.length()]='\0';
    curr.price = convertTextToNumber(chArr);
    return curr;
}

WorkoutType Studio::defineWorkoutType(std::string str) {
    if(str.compare("Anaerobic")==0) {
        return ANAEROBIC;
    }
    else if (str.compare("Mixed")==0) {
        return MIXED;
    }
    else
        return CARDIO;
}

int Studio::getNumOfTrainers() const {
    return (int)trainers.size();
}

Trainer *Studio::getTrainer(int tid) {
    if(tid < 0 || tid>=getNumOfTrainers()){
        return nullptr;
    }
    return trainers[tid];
}

const std::vector<BaseAction *> &Studio::getActionsLog() const {
    return actionsLog;
}

std::vector<Workout> &Studio::getWorkoutOptions() {
    return workout_options;
}

int Studio::getNewCustomerId() {
    return newCustomerId;
}

void Studio::setNewCustomerId() {
    newCustomerId++;
}

void Studio::closeStudio() {
    open=false;
}

std::string Studio::getActionName(std::string userInput) {
    return "";
}

void Studio::setBackup() {
    isBackedup=true;
}

bool Studio::getIsBackedup() {
    return isBackedup;
}

void Studio::decreseNewCustomerId() {
    newCustomerId--;
}