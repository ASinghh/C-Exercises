#include <iostream>
#include <string>
using std::string;

class Vehicle {
public:
    int wheels;
    string color = "blue";
    string fuel = "petroleum";
    
    void Print() const
    {
        std::cout << "This " << color << " vehicle has " << wheels << " wheels"<<" and runs on "<<fuel<<"!\n";
    }
};

class Car : public Vehicle {
public:
    bool sunroof = false;
};

class Bicycle : public Vehicle {
public:
    bool kickstand = true;

};

int main() 
{
    Car car;
    car.wheels = 4;
    car.sunroof = true;
    car.Print();
    Bicycle bi;
    bi.wheels = 2;
    bi.fuel = "muscle power";
    bi.color = "red";
    bi.Print();
    if(car.sunroof)
        std::cout << "And a sunroof!\n";
};
