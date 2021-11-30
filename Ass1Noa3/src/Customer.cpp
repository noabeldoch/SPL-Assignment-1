#include <climits>
#include <algorithm>
#include <unordered_set>
#include "../include/Customer.h"

//-----Customer------

Customer::Customer(std::string c_name, int c_id): name(c_name), id(c_id){}

Customer::~Customer()=default;


std::string Customer::getName() const {
    return name;
}

int Customer::getId() const {
    return id;
}

//-----SweatyCustomer------

SweatyCustomer::SweatyCustomer(std::string name, int id) : Customer(name, id){}

SweatyCustomer *SweatyCustomer::clone() {
    return new SweatyCustomer(*this);
}

std::vector<int> SweatyCustomer::order(const std::vector<Workout> &workout_options) {
    std::vector<int> SweatyCustomerOrder;
    for (std::size_t i=0; i<workout_options.size(); i++) {
        if(workout_options[i].getType()==CARDIO) {
            SweatyCustomerOrder.push_back(workout_options[i].getId());
        }
    }
    return SweatyCustomerOrder;
}

std::string SweatyCustomer::getType() const {
    return "swt";
}

std::string SweatyCustomer::toString() const {
    return "";
}


//-----CheapCustomer------

CheapCustomer::CheapCustomer(std::string name, int id) : Customer(name, id){}

CheapCustomer *CheapCustomer::clone() {
    return new CheapCustomer(*this);
}

std::vector<int> CheapCustomer::order(const std::vector<Workout> &workout_options) {
    std::vector<int> CheapCustomerOrder;
    if(workout_options.size()==0) {
        return CheapCustomerOrder;
    }
    else {
        int minPrice = INT_MAX;
        int minId = -1;
        for (std::size_t i = 0; i < workout_options.size(); i++) {
            if (workout_options[i].getPrice() < minPrice) {
                minPrice = workout_options[i].getPrice();
                minId = workout_options[i].getId();
            }
        }
        CheapCustomerOrder.push_back(minId);
        return CheapCustomerOrder;
    }
}

std::string CheapCustomer::getType() const {
    return "chp";
}

std::string CheapCustomer::toString() const {
    return "";
}

//-----HeavyMuscleCustomer------

HeavyMuscleCustomer::HeavyMuscleCustomer(std::string name, int id) : Customer(name, id){}

HeavyMuscleCustomer *HeavyMuscleCustomer::clone() {
    return new HeavyMuscleCustomer(*this);
}

std::vector<int> HeavyMuscleCustomer::order(const std::vector<Workout> &workout_options) {
    std::vector<Workout> anaerobicWorkout;
    std::vector<Workout> sortedAnaerobicWorkout;
    std::vector<int> HeavyCustomerOrder;

    for (std::size_t i=0; i<workout_options.size(); i++) {
        if(workout_options[i].getType()==ANAEROBIC) {
            anaerobicWorkout.push_back(workout_options[i]);
        }
    }

    int minPrice=INT_MAX;
    std::unordered_set<int> hash = {};
    int minId = -1;
    for(std::size_t j=0; j<anaerobicWorkout.size(); j++) {
        minPrice=INT_MAX;
        for(std::size_t i=0; i<anaerobicWorkout.size(); i++) {
            if (anaerobicWorkout[i].getPrice() < minPrice && hash.find(i)==hash.end()) {
                minPrice = anaerobicWorkout[i].getPrice();
                minId = i;
            }
        }
        sortedAnaerobicWorkout.push_back(anaerobicWorkout[minId]);
        hash.insert(minId);
    }

    int size = sortedAnaerobicWorkout.size();
    for (int i=size-1; i>=0; i--) {
        HeavyCustomerOrder.push_back(sortedAnaerobicWorkout[i].getId());
    }

    return HeavyCustomerOrder;
}

std::string HeavyMuscleCustomer::getType() const {
    return "mcl";
}

std::string HeavyMuscleCustomer::toString() const {
    return "";
}


//-----FullBodyCustomer------

FullBodyCustomer::FullBodyCustomer(std::string name, int id) : Customer(name, id){}

FullBodyCustomer* FullBodyCustomer::clone() {
    return new FullBodyCustomer(*this);
}

std::vector<int> FullBodyCustomer::order(const std::vector<Workout> &workout_options) {
    int cheapestCardio=-1;
    int expensiveMixed=-1;
    int cheapestAnaerobic=-1;
    std::vector<int> FullBodyCustomerOrder;
    for(std::size_t i=0; i<workout_options.size(); i++) {
        switch (workout_options[i].getType()){
            case ANAEROBIC: {
                if(cheapestAnaerobic==-1)
                    cheapestAnaerobic=workout_options[i].getId();
                else if(workout_options[cheapestAnaerobic].getPrice()>workout_options[i].getPrice())
                    cheapestAnaerobic=workout_options[i].getId();
                break;
            }
            case MIXED: {
                if(expensiveMixed==-1)
                    expensiveMixed=workout_options[i].getId();
                else if(workout_options[expensiveMixed].getPrice()<workout_options[i].getPrice())
                    expensiveMixed=workout_options[i].getId();
                break;
            }
            case CARDIO: {
                if(cheapestCardio==-1)
                    cheapestCardio=workout_options[i].getId();
                else if(workout_options[cheapestCardio].getPrice()>workout_options[i].getPrice())
                    cheapestCardio=workout_options[i].getId();
                break;
            }
        }
    }
    if(cheapestAnaerobic!=-1 && expensiveMixed!=-1 && cheapestCardio!=-1) {
        FullBodyCustomerOrder.push_back(workout_options[cheapestCardio].getId());
        FullBodyCustomerOrder.push_back(workout_options[expensiveMixed].getId());
        FullBodyCustomerOrder.push_back(workout_options[cheapestAnaerobic].getId());
    }
    return FullBodyCustomerOrder;
}

std::string FullBodyCustomer::getType() const {
    return "fbd";
}

std::string FullBodyCustomer::toString() const {
    return "";
}


