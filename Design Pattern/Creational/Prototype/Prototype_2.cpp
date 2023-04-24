/*
The Prototype Design Pattern is a creational design pattern that allows us to copy existing objects without making our code dependent on their classes.
This pattern involves implementing a prototype interface that tells the system to create a clone of the current object. The Prototype Pattern is used
when creating an object is costly or complex, and we want to avoid repeating the same initialization process multiple times. By using this pattern,
we can create new objects by copying existing ones, which can save time and resources. This pattern is commonly used in software systems that need to
create many similar objects with slight variations, such as graphical user interfaces or game engines.

*/

#include <iostream>
#include <memory>

class Car {
public:
    virtual ~Car() {}

    virtual std::unique_ptr<Car> clone() const = 0;

    virtual void setDescription(const std::string& description) {
        m_description = description;
    }

    virtual std::string getDescription() const {
        return m_description;
    }

private:
    std::string m_description;
};

class Mustang : public Car {
public:
    std::unique_ptr<Car> clone() const override {
        return std::make_unique<Mustang>(*this);
    }
};

class Camaro : public Car {
public:
    std::unique_ptr<Car> clone() const override {
        return std::make_unique<Camaro>(*this);
    }
};

int main() {
   // Create a Ford Mustang
   auto mustang = std::make_unique<Mustang>();
   mustang->setDescription("This is a Ford Mustang.");

   // Clone the Ford Mustang to create a Chevrolet Camaro
   auto camaro = mustang->clone();
   camaro->setDescription("This is a Chevrolet Camaro.");

   // Print the descriptions of the cars
   std::cout << mustang->getDescription().c_str() << "\n";
   std::cout << camaro->getDescription().c_str() << "\n";

   return 0;
}