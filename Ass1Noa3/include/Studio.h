#ifndef STUDIO_H_
#define STUDIO_H_

#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

#include "Workout.h"
#include "Trainer.h"
#include "Action.h"

using namespace std;

class Studio{
public:
    Studio();
    Studio(const std::string &configFilePath);
    ~Studio();
    Studio(const Studio& other);
    Studio& operator=(const Studio& other);
    Studio(Studio&& other);
    Studio& operator=(Studio&& other);
    void start();
    int getNumOfTrainers() const;
    Trainer* getTrainer(int tid);
    const std::vector<BaseAction*>& getActionsLog() const;
    std::vector<Workout>& getWorkoutOptions();
    string getActionName(string userInput);
    int convertTextToNumber(char* line);
    int getNewCustomerId();
    void setNewCustomerId();
    void decreseNewCustomerId();
    void setBackup();
    bool getIsBackedup ();
    void closeStudio();
    std::vector<std::string> actionToString(std::string action);
    void clear();


private:
    bool open;
    bool isBackedup;
    int newCustomerId;
    std::vector<Trainer*> trainers;
    std::vector<Workout> workout_options;
    std::vector<BaseAction*> actionsLog;

    struct workoutOptions{
        std::string name;
        WorkoutType type;
        int price;
    };

    //functions for the config file analysis:
    void defineTrainersCapacity(char *line);
    WorkoutType defineWorkoutType(std::string str);
    workoutOptions extractWordFromString(char *line);

};

#endif
