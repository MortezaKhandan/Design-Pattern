/*
The Decorator design pattern is a structural pattern that allows you to add new behaviors or functionalities to an object dynamically
by wrapping it with one or more decorator objects. It allows you to modify the behavior of an object without changing its original class or code.

In other words, the Decorator pattern involves creating a decorator class that wraps the original class and provides additional functionality
or behavior. The decorator class implements the same interface as the original class, and it can add or modify its behavior by adding its own
methods or by intercepting and modifying the original class methods.

There are several reasons why you might want to use the Decorator design pattern:

1. Flexibility: The Decorator pattern allows you to add or remove functionalities or behaviors from an object at runtime.
This makes it easy to modify the behavior of an object without changing its underlying implementation.

2. Extensibility: The Decorator pattern allows you to add new functionalities or behaviors to an object by creating new decorator classes.
This makes it easy to extend the functionality of an object without modifying its original implementation.

3. Composition: The Decorator pattern promotes composition over inheritance, which is a principle of object-oriented programming.
This allows you to combine multiple decorators to create complex and dynamic behaviors.

4. Separation of concerns: The Decorator pattern separates the responsibilities of an object into multiple classes. This makes it easier
to manage and modify the behavior of an object by isolating the functionality into smaller, more focused classes.

5. Open-closed principle: The Decorator pattern follows the open-closed principle, which states that classes should be open for extension
but closed for modification. This means that you can add new functionality to an object without modifying its original implementation,
which can help to avoid introducing bugs and reduce maintenance costs.

Overall, the Decorator pattern is a powerful tool for adding flexible and extensible behaviors to an object-oriented system. It can help
you to create more modular and maintainable code, and it is particularly useful in situations where you need to modify or extend the behavior
of an object dynamically.

*/


#include <iostream>
#include <memory>

class Coffee {
public:
    virtual ~Coffee() {}

    virtual std::string getDescription() const = 0;

    virtual double getCost() const = 0;
};

class Espresso : public Coffee {
public:
    std::string getDescription() const override {
        return "Espresso";
    }

    double getCost() const override {
        return 1.99;
    }
};

class CondimentDecorator : public Coffee {
public:
    CondimentDecorator(std::unique_ptr<Coffee> coffee) : m_coffee{std::move(coffee)} {}

    std::string getDescription() const override {
        return m_coffee->getDescription();
    }

    double getCost() const override {
        return m_coffee->getCost();
    }

private:
   std::unique_ptr<Coffee> m_coffee;
};

class Milk : public CondimentDecorator {
public:
   Milk(std::unique_ptr<Coffee> coffee) : CondimentDecorator{std::move(coffee)} {}

   std::string getDescription() const override {
       return CondimentDecorator::getDescription() + ", Milk";
   }

   double getCost() const override {
       return CondimentDecorator::getCost() + 0.25;
   }
};

class Sugar : public CondimentDecorator {
public:
   Sugar(std::unique_ptr<Coffee> coffee) : CondimentDecorator{std::move(coffee)} {}

   std::string getDescription() const override {
       return CondimentDecorator::getDescription() + ", Sugar";
   }

   double getCost() const override {
       return CondimentDecorator::getCost() + 0.10;
   }
};

int main()
{
   // Create a concrete component
   auto espresso = std::make_unique<Espresso>();

   // Wrap the concrete component with decorators
   auto milkEspresso = std::make_unique<Milk>(std::move(espresso));
   auto sugarMilkEspresso = std::make_unique<Sugar>(std::move(milkEspresso));

   // Call the decorated operations
   std::cout << sugarMilkEspresso->getDescription().c_str(); // Output: Espresso, Milk, Sugar
   std::cout << "\nTotal cost: $" << sugarMilkEspresso->getCost(); // Output: Total cost: $2.34

   return 0;
}

