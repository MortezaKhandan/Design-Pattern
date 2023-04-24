/*
The Facade Design Pattern is a structural design pattern that provides a simplified interface to a library, framework, or any other complex set of classes.
It defines a higher-level interface that makes the subsystem easier to use by wrapping a complicated subsystem with a simpler interface. The goal of this
pattern is to provide an easy-to-use interface for clients to interact with complex systems without having to understand their underlying complexities.
One way to achieve this goal is to introduce a facade object that provides a single, simplified interface to the more general facilities of a subsystem.
This pattern helps us decouple our code by hiding the complexity of the system behind an easy-to-use interface, making it easier for clients to use and
maintain our codebase.

*/

#include <iostream>

// Complex subsystem classes
class SubsystemA {
public:
    void operationA() {
        std::cout << "Subsystem A operation" << std::endl;
    }
};

class SubsystemB {
public:
    void operationB() {
        std::cout << "Subsystem B operation" << std::endl;
    }
};

// Facade class
class Facade {
public:
    Facade() {
        subsystemA = new SubsystemA();
        subsystemB = new SubsystemB();
    }
    
    ~Facade() {
        delete subsystemA;
        delete subsystemB;
    }
    
    void operation() {
        subsystemA->operationA();
        subsystemB->operationB();
    }
    
private:
    SubsystemA* subsystemA;
    SubsystemB* subsystemB;
};

// Client code
int main() {
    Facade* facade = new Facade();
    facade->operation();
    delete facade;
    return 0;
}
