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


class Application{
    RunningStrategy* runningStrategy;
    public:
        Application(RunningStrategy* ptr){
            this->runningStrategy = ptr;
        }
        void drive(){
            runningStrategy->run();
        }
};

int main()
{
    Application app = Application(new OldRunningStrategy());
    app.drive();
}
