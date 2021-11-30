#include "../include/Workout.h"

#include <climits>

Workout::Workout(int w_id, std::string w_name, int w_price, WorkoutType w_type):
id(w_id), name(w_name), price(w_price), type(w_type) {}

//Copy constructor
Workout::Workout(const Workout &other) :
id(other.getId()), name(other.getName()), price(other.getPrice()), type(other.getType()){}

int Workout::getId() const {
    return id;
}

std::string Workout::getName() const {
    return name;
}

int Workout::getPrice() const {
    return price;
}

WorkoutType Workout::getType() const {
    return type;
}

std::string Workout::toString() {
    switch (type) {
        case ANAEROBIC: {
            return "Anaerobic";
            break;
        }
        case MIXED: {
            return "Mixed";
            break;
        }
        case CARDIO: {
            return "Cardio";
            break;
        }
    }
    return "";
}


