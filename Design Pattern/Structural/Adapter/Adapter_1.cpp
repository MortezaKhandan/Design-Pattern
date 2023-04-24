/*
The Adapter Design Pattern is a structural design pattern that allows objects with incompatible interfaces to collaborate.
It converts the interface of a class into another interface that clients expect, making it easier for otherwise incompatible
classes to work together. The Adapter Pattern is particularly useful when we need to integrate existing code with new code or
when we need to reuse existing code in a new context. This pattern helps us decouple our code by allowing us to create adapters
that act as intermediaries between two incompatible interfaces, without having to modify the underlying classes. The Adapter
Pattern is commonly used in software systems that need to interact with external libraries or legacy systems.

*/


#include <iostream>

// Adaptee: defines the existing interface that needs adapting
class Square {
public:
    virtual void draw() {
        std::cout << "Drawing a square." << std::endl;
    }
};

// Target: defines the desired interface that the client uses
class Shape {
public:
    virtual void display() = 0;
};

// Adapter: adapts the interface of the Adaptee to the Target interface
class SquareAdapter : public Shape {
public:
    SquareAdapter(Square* square) : m_square(square) {}
    void display() override {
        m_square->draw();
    }
private:
    Square* m_square;
};

int main() {
    // Adaptee
    Square square;

    // Adapter
    Shape* shape = new SquareAdapter(&square);

    // Client
    shape->display();

    return 0;
}
