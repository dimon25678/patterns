#include <iostream>
#include <memory>

// Abstract Product A - Vehicle
class Vehicle {
public:
    virtual ~Vehicle() {}
    virtual void displayInfo() const = 0;
};

// Concrete Product A1 - Car
class Car : public Vehicle {
public:
    void displayInfo() const override {
        std::cout << "This is a Car." << std::endl;
    }
};

// Concrete Product A2 - Bicycle
class Bicycle : public Vehicle {
public:
    void displayInfo() const override {
        std::cout << "This is a Bicycle." << std::endl;
    }
};

// Abstract Product B - Factory
class Factory {
public:
    virtual std::unique_ptr<Vehicle> createVehicle() const = 0;
};

// Concrete Factory 1 - Car Factory
class CarFactory : public Factory {
public:
    std::unique_ptr<Vehicle> createVehicle() const override {
        return std::make_unique<Car>();
    }
};

// Concrete Factory 2 - Bicycle Factory
class BicycleFactory : public Factory {
public:
    std::unique_ptr<Vehicle> createVehicle() const override {
        return std::make_unique<Bicycle>();
    }
};

int main() {
    // Creating a Car using Car Factory
    std::unique_ptr<Factory> carFactory = std::make_unique<CarFactory>();
    std::unique_ptr<Vehicle> car = carFactory->createVehicle();
    car->displayInfo();

    // Creating a Bicycle using Bicycle Factory
    std::unique_ptr<Factory> bicycleFactory = std::make_unique<BicycleFactory>();
    std::unique_ptr<Vehicle> bicycle = bicycleFactory->createVehicle();
    bicycle->displayInfo();

    return 0;
}
