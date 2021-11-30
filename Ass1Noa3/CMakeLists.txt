cmake_minimum_required(VERSION 3.20)
project(Ass1Noa3)

set(CMAKE_CXX_STANDARD 11)

add_executable(Ass1Noa3 src/main.cpp include/Studio.h include/Workout.h include/Trainer.h include/Customer.h include/Action.h src/Studio.cpp src/Workout.cpp src/Trainer.cpp src/Customer.cpp src/Action.cpp)
