#include<bits/stdc++.h>
using namespace std;

class RunningStrategy{
    public: 
        virtual void run() = 0;
};

class OldRunningStrategy : public RunningStrategy{
    public:
        void run(){
            cout<<"Using Old running strategy\n";
        }
};

class NewRunningStrategy : public RunningStrategy{
    public:
        void run(){
            cout<<"Using New running strategy\n";
        }
};


class Vehicle{
    public: RunningStrategy* runningStrategy;
    public: virtual void run() = 0;
};
class Bike : public Vehicle{
    public:
        Bike(RunningStrategy* runningStrategy){
            this->runningStrategy = runningStrategy;
        }
        void run(){
            this->runningStrategy->run();
        }
};
class Car  : public Vehicle{
    public:
        Car(RunningStrategy* runningStrategy){
            this->runningStrategy = runningStrategy;
        }
        void run(){
            this->runningStrategy->run();
        }
};

int main()
{
    Vehicle* app = new Car(new OldRunningStrategy());
    app->run();
}
