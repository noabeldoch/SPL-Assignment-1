#include "../include/Trainer.h"

Trainer::Trainer(int t_capacity): salary(0), capacity(t_capacity), open(false), isEverOpened(false), wasOrdered(false) { }


Trainer::~Trainer(){
    for(std::size_t i=0; i<customersList.size(); i++) {
        delete customersList[i];
        customersList[i]= nullptr;
    }
    customersList.clear();
}

Trainer::Trainer(const Trainer& other):
    salary(other.salary), capacity(other.capacity), open(other.open), isEverOpened(other.isEverOpened), wasOrdered(other.wasOrdered){

    for(std::size_t i=0; i<other.customersList.size(); i++) {
        this->customersList.push_back(other.customersList[i]->clone());
    }

    for (std::size_t i=0; i<other.orderList.size(); i++) {
        orderList.push_back(std::make_pair(other.orderList[i].first,other.orderList[i].second));
    }
}

Trainer& Trainer::operator=(const Trainer& other){
    salary=other.salary;
    capacity=other.capacity;
    open=other.open;
    isEverOpened=other.isEverOpened;
    wasOrdered=other.wasOrdered;

    for(std::size_t i=0; i<customersList.size(); i++) {
       delete customersList[i];
    }
    customersList.clear();
    orderList.clear();

    for(std::size_t i=0; i<other.customersList.size(); i++) {
        this->customersList.push_back(other.customersList[i]->clone());
    }

    for (std::size_t i=0; i<other.orderList.size(); i++) {
        orderList.push_back(std::make_pair(other.orderList[i].first,other.orderList[i].second));
    }
    return *this;
}

Trainer::Trainer(Trainer&& other):
    salary(other.salary), capacity(other.capacity), open(other.open), isEverOpened(other.isEverOpened), wasOrdered(other.wasOrdered){

    this->orderList.clear();
    for(std::size_t i=0; i<other.orderList.size(); i++){
        this->orderList.push_back(other.orderList[i]);
    }
    other.orderList.clear();

    for(std::size_t i=0; i<customersList.size(); i++) {
        delete customersList[i];
    }
    customersList.clear();

    for(std::size_t i=0; i<other.customersList.size(); i++) {
        this->customersList.push_back(other.customersList[i]);
    }
    other.customersList.clear();
}


Trainer& Trainer::operator=(Trainer&& other){
    if (this!=&other) {
        salary=other.salary;
        capacity=other.capacity;
        open=other.open;
        isEverOpened=other.isEverOpened;
        wasOrdered=other.wasOrdered;

        this->orderList.clear();
        for(std::size_t i=0; i<other.orderList.size(); i++){
            this->orderList.push_back(other.orderList[i]);
        }
        other.orderList.clear();

        for(std::size_t i=0; i<customersList.size(); i++) {
            delete customersList[i];
        }
        this->customersList.clear();
        for(std::size_t i=0; i<other.customersList.size(); i++) {
            this->customersList.push_back(other.customersList[i]);
        }
        other.customersList.clear();
    }
    return *this;
}



int Trainer::getCapacity() const {
    return capacity;
}

void Trainer::addCustomer(Customer *customer) {
    customersList.push_back(customer);
}

void Trainer::removeCustomer(int id) {
    int index;
    for(std::size_t i=0; i<customersList.size(); i++) {
        if(customersList[i]->getId()==id) {
            index = i;
            customersList[i]= nullptr;
        }
    }
    customersList.erase(customersList.begin()+index);

    std::vector <OrderPair > temp;
    for(std::size_t i=0; i<orderList.size(); i++) {
        if(orderList[i].first!=id) {
            temp.push_back(orderList[i]);
        }
    }
    orderList.clear();
    for(std::size_t i=0; i<temp.size(); i++) {
        orderList.push_back(temp[i]);
    }
}

Customer* Trainer::getCustomer(int id) {
    for(std::size_t i=0; i<customersList.size(); i++) {
        if(customersList[i]->getId()==id)
            return customersList[i];
    }
    return nullptr;
}

std::vector<Customer*>& Trainer::getCustomers() {
    return customersList;
}

std::vector<OrderPair>& Trainer::getOrders() {
    return orderList;
}

void Trainer::order(const int customer_id, const std::vector<int> workout_ids, const std::vector<Workout> &workout_options) {
    for (std::size_t i=0; i<workout_ids.size(); i++) {
        Workout w(workout_options[workout_ids[i]]);
        orderList.push_back(std::make_pair(customer_id,w));
    }
}

void Trainer::openTrainer() {
    open=true;
    isEverOpened=true;
}

//Test close Trainer *******************
void Trainer::closeTrainer() {
    open=false;
    wasOrdered=false;
    for(std::size_t i=0; i<customersList.size(); i++){
        delete customersList[i];
        customersList[i]= nullptr;
    }
    customersList.clear();
    orderList.clear();
}

int Trainer::getSalary() {
    return salary;
}

bool Trainer::isOpen() {
    return open;
}

void Trainer::updateSalary(){
    int sessionSalary = 0;
    for (std::size_t i=0 ; i<orderList.size() ; i++){
        sessionSalary += orderList[i].second.getPrice();
    }
    salary += sessionSalary;
}

void Trainer::addExistCustomer(Customer* customer) {
    bool inserted = false;
    for(std::size_t i=0; i<customersList.size() && !inserted; i++){
        if(customer->getId() < customersList[i]->getId()) {
            auto itPos = customersList.begin() + i;
            customersList.insert(itPos, customer);
            inserted = true;
        }
    }
    if(!inserted) {
        customersList.push_back(customer);
    }
}

void Trainer::addExistOrder(const int customer_id, const std::vector<int> workout_ids, const std::vector<Workout> &workout_options) {
    std::vector <OrderPair> temp;
    bool inserted = false;
    for (std::size_t i=0; i<orderList.size(); i++) {
        if(customer_id < orderList[i].first && !inserted) {
            for (std::size_t j=0; j<workout_ids.size(); j++) {
                Workout w(workout_options[workout_ids[j]]);
                temp.push_back(std::make_pair(customer_id,w));
            }
            inserted=true;
            i--;
        }
        else {
            temp.push_back(orderList[i]);
        }
    }
    if(!inserted) {
        for (std::size_t j=0; j<workout_ids.size(); j++) {
            Workout w(workout_options[workout_ids[j]]);
            temp.push_back(std::make_pair(customer_id,w));
        }
    }
    orderList.clear();
    for(std::size_t i=0; i<temp.size(); i++) {
        orderList.push_back(temp[i]);
    }
    temp.clear();
}

bool Trainer::getIsEverOpened() {
    return isEverOpened;
}

bool Trainer::getWasOrdered() {
    return wasOrdered;
}
void Trainer::setWasOrdered(bool val){
    wasOrdered=val;
}