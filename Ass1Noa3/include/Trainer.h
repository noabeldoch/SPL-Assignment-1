#ifndef TRAINER_H_
#define TRAINER_H_

#include <vector>
#include "../include/Customer.h"
#include "../include/Workout.h"

typedef std::pair<int, Workout> OrderPair;

class Trainer{
public:
    Trainer(int t_capacity);
    ~Trainer();
    Trainer(const Trainer& other);
    Trainer& operator=(const Trainer& other);
    Trainer(Trainer&& other);
    Trainer& operator=(Trainer&& other);

    int getCapacity() const;
    void addCustomer(Customer* customer);
    void removeCustomer(int id);
    Customer* getCustomer(int id);
    std::vector<Customer*>& getCustomers();
    std::vector<OrderPair>& getOrders();
    void order(const int customer_id, const std::vector<int> workout_ids, const std::vector<Workout>& workout_options);
    void openTrainer();
    void closeTrainer();
    int getSalary();
    bool isOpen();
    void updateSalary();
    void addExistCustomer(Customer *customer);
    void addExistOrder(const int customer_id, const std::vector<int> workout_ids, const std::vector<Workout> &workout_options);
    bool getIsEverOpened();
    bool getWasOrdered();
    void setWasOrdered(bool val);


private:
    int salary;
    int capacity;
    bool open;
    bool isEverOpened;
    bool wasOrdered;
    std::vector<Customer*> customersList;
    std::vector<OrderPair> orderList;

};

#endif
