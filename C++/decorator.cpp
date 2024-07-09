#include<bits/stdc++.h>
using namespace std;

class Pizza{
    public : int virtual cost() = 0;
};

class ThickCrustPizza : public Pizza{
    public : int cost(){
        return 200;
    }
};

class ThinCrustPizza : public Pizza{
    public : int cost(){
        return 400;
    }
};

class Toppings : public Pizza{
    public : Pizza* pizza;
    public : int cost(){
        return 0;
    }
};

class Cheese : public Toppings{
    public : Cheese(Pizza* pizza){
        this->pizza = pizza;
    }
    public : int cost(){
        return this->pizza->cost() + 20;
    }
};

class Corn : public Toppings{
    public : Corn(Pizza* pizza){
        this->pizza = pizza;
    }
    public : int cost(){
        return this->pizza->cost() + 10;
    }
};

class Onion : public Toppings{
    public : Onion(Pizza* pizza){
        this->pizza = pizza;
    }
    public : int cost(){
        return this->pizza->cost() + 5;
    }
};

int main()
{
    Pizza* pizza = new Corn(new Onion(new Cheese(new ThickCrustPizza())));
    cout<<pizza->cost()<<endl;
}
