
#include <iostream>

// Basic component interface
class Coffee {
public:
    virtual double getCost() = 0;
};

// Concrete component class
class BasicCoffee : public Coffee {
public:
    double getCost() override {
        return 1.00;
    }
};

// Decorator class
class CoffeeDecorator : public Coffee {
protected:
    Coffee* coffee;

public:
    CoffeeDecorator(Coffee* coffee) {
        this->coffee = coffee;
    }

    double getCost() override {
        return coffee->getCost();
    }
};

// Concrete decorator class
class Milk : public CoffeeDecorator {
public:
    Milk(Coffee* coffee) : CoffeeDecorator(coffee) {}

    double getCost() override {
        return coffee->getCost() + 0.50;
    }
};

// Client code
int main() {
    Coffee* myCoffee = new BasicCoffee();
    Coffee* myLatte = new Milk(myCoffee);
    std::cout << myLatte->getCost() << std::endl; // Output: 1.5

    delete myCoffee;
    delete myLatte;
    return 0;
}
