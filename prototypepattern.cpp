#include <iostream>
#include <string>
#include <memory>

// Abstract base class - Prototype
class Prototype {
public:
    virtual ~Prototype() {}
    virtual std::unique_ptr<Prototype> clone() const = 0;
    virtual void performAction() const = 0;
};

// Concrete class implementing the Prototype
class ConcretePrototype : public Prototype {
private:
    std::string data;

public:
    ConcretePrototype(const std::string& data) : data(data) {}

    // Method for cloning the prototype object
    std::unique_ptr<Prototype> clone() const override {
        return std::make_unique<ConcretePrototype>(*this);
    }

    // Method to perform an action with the prototype
    void performAction() const override {
        std::cout << "ConcretePrototype: " << data << std::endl;
    }
};

int main() {
    // Creating a prototype object
    std::unique_ptr<Prototype> prototype = std::make_unique<ConcretePrototype>("Initial data");

    // Cloning the prototype
    std::unique_ptr<Prototype> clone = prototype->clone();

    // Performing an action with the cloned prototype
    clone->performAction();

    return 0;
}
