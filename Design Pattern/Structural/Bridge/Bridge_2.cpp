/*
The Bridge Design Pattern is a structural design pattern that lets you split a large class or a set of closely related classes into two separate hierarchies:
abstraction and implementation. This pattern is used when we need to decouple an abstraction from its implementation so that the two can vary independently.
The Bridge Pattern decouples the implementation class and abstract class by providing a bridge structure between them. The goal of this pattern is to allow
changes to be made in one part of the system without affecting other parts of the system. This pattern helps us decouple our code by allowing us to create
abstractions and implementations that can vary independently, without having to modify the underlying classes. The Bridge Pattern is commonly used in software
systems that need to support multiple platforms or devices with different capabilities.

*/
#include <iostream>
#include <memory>

// Implementor
class Renderer {
public:
    virtual void renderCircle() = 0;
    virtual void renderSquare() = 0;
    virtual ~Renderer() {}
};

// Concrete Implementor
class DirectXRenderer : public Renderer {
public:
    void renderCircle() {
        std::cout << "DirectXRenderer rendering circle" << std::endl;
    }
    void renderSquare() {
        std::cout << "DirectXRenderer rendering square" << std::endl;
    }
};

class OpenGLRenderer : public Renderer {
public:
    void renderCircle() {
        std::cout << "OpenGLRenderer rendering circle" << std::endl;
    }
    void renderSquare() {
        std::cout << "OpenGLRenderer rendering square" << std::endl;
    }
};

// Abstraction
class Shape {
public:
    Shape() {}
    virtual void draw() = 0;
    virtual ~Shape() {}
};

// Refined Abstraction
class CircleShape : public Shape {
public:
    CircleShape(std::shared_ptr<Renderer> renderer) : renderer_(renderer) {}
    void draw() {
        renderer_->renderCircle();
    }
private:
    std::shared_ptr<Renderer> renderer_;
};

class SquareShape : public Shape {
public:
    SquareShape(std::shared_ptr<Renderer> renderer) : renderer_(renderer) {}
    void draw() {
        renderer_->renderSquare();
    }
private:
    std::shared_ptr<Renderer> renderer_;
};

int main() {
    std::shared_ptr<DirectXRenderer> dxRenderer = std::make_shared<DirectXRenderer>();
    std::shared_ptr<OpenGLRenderer> glRenderer = std::make_shared<OpenGLRenderer>();

    CircleShape circle(dxRenderer);
    circle.draw(); // Output: DirectXRenderer rendering circle

    SquareShape square(glRenderer);
    square.draw(); // Output: OpenGLRenderer rendering square

    return 0;
}
