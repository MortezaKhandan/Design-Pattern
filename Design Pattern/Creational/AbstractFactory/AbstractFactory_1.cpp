/*
The Abstract Factory Design Pattern is a creational design pattern that provides a way to create families of related objects without specifying
their concrete classes. It works around a super-factory which creates other factories, and is also called as factory of factories.
This pattern helps us decouple our code by allowing us to create objects without having to know their specific class names or implementation details.
It also makes it easier to add new types of objects without having to modify existing code. The Abstract Factory Pattern lets you produce families of
related objects without specifying their concrete classes,by encapsulating a group of individual factories that have a common theme.



*/


#include <iostream>
using namespace std;

// Abstract product classes
class Chair {
public:
    virtual void sit() = 0;
};

class Sofa {
public:
    virtual void lieDown() = 0;
};

// Concrete product classes
class VictorianChair : public Chair {
public:
    void sit() {
        cout << "Sitting on a Victorian chair" << endl;
    }
};

class VictorianSofa : public Sofa {
public:
    void lieDown() {
        cout << "Lying down on a Victorian sofa" << endl;
    }
};

class ModernChair : public Chair {
public:
    void sit() {
        cout << "Sitting on a modern chair" << endl;
    }
};

class ModernSofa : public Sofa {
public:
    void lieDown() {
        cout << "Lying down on a modern sofa" << endl;
    }
};

// Abstract factory class
class FurnitureFactory {
public:
    virtual Chair* createChair() = 0;
    virtual Sofa* createSofa() = 0;
};

// Concrete factory classes
class VictorianFurnitureFactory : public FurnitureFactory {
public:
    Chair* createChair() {
        return new VictorianChair();
    }
    Sofa* createSofa() {
        return new VictorianSofa();
    }
};

class ModernFurnitureFactory : public FurnitureFactory {
public:
    Chair* createChair() {
        return new ModernChair();
    }
    Sofa* createSofa() {
        return new ModernSofa();
    }
};

int main() {
    // Create a Victorian furniture factory
    FurnitureFactory* victorianFactory = new VictorianFurnitureFactory();
    Chair* victorianChair = victorianFactory->createChair();
    Sofa* victorianSofa = victorianFactory->createSofa();

    victorianChair->sit();
    victorianSofa->lieDown();

    // Create a modern furniture factory
    FurnitureFactory* modernFactory = new ModernFurnitureFactory();
    Chair* modernChair = modernFactory->createChair();
    Sofa* modernSofa = modernFactory->createSofa();

    modernChair->sit();
    modernSofa->lieDown();

    // Clean up memory
    delete victorianChair;
    delete victorianSofa;
    delete victorianFactory;
    delete modernChair;
    delete modernSofa;
    delete modernFactory;

    return 0;
}
