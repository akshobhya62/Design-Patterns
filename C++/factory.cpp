#include<bits/stdc++.h>
using namespace std;

class Vehicle{
    public:
        virtual void run() = 0;
};
class Bike : public Vehicle{
    public:
        void run(){
            cout<<"Running Bike\n";
        }
};
class Car  : public Vehicle{
    public:
        void run(){
            cout<<"Running Car\n";
        }
};

class VehicleFactory{
    public: 
        virtual Vehicle* createVehicle() = 0;
};

class BikeFactory : public VehicleFactory{
    public:
        Vehicle* createVehicle(){
            return new Bike();
        }
};

class CarFactory : public VehicleFactory{
    public:
        Vehicle* createVehicle(){
            return new Car();
        }
};

class Application{
    VehicleFactory* vehicleFactory;
    public:
        Application(VehicleFactory* ptr){
            this->vehicleFactory = ptr;
        }
        Vehicle* getVehicle(){
            return vehicleFactory->createVehicle();
        }
};

int main()
{
    Application app = Application(new BikeFactory());
    app.getVehicle()->run();
}
