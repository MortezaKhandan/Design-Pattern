#include <iostream>
#include <memory>

// Implementor interface
class Color {
public:
    virtual std::string getColor() = 0;
    virtual ~Color() {}
};

// Concrete Implementors
class RedColor : public Color {
public:
    std::string getColor() override {
        return "Red";
    }
};

class GreenColor : public Color {
public:
    std::string getColor() override {
        return "Green";
    }
};

class BlueColor : public Color {
public:
    std::string getColor() override {
        return "Blue";
    }
};

// Abstraction interface
class Shape {
public:
    Shape(std::shared_ptr<Color> color) : color_(color) {}
    virtual std::string getName() = 0;
    virtual std::string getShape() = 0;
    virtual ~Shape() {}
protected:
    std::shared_ptr<Color> color_;
};

// Refined Abstractions
class Triangle : public Shape {
public:
    Triangle(std::shared_ptr<Color> color) : Shape(color) {}
    std::string getName() override {
        return "Triangle";
    }
    std::string getShape() override {
        return color_->getColor() + " " + getName();
    }
};

class Square : public Shape {
public:
    Square(std::shared_ptr<Color> color) : Shape(color) {}
    std::string getName() override {
        return "Square";
    }
    std::string getShape() override {
        return color_->getColor() + " " + getName();
    }
};

class Circle : public Shape {
public:
    Circle(std::shared_ptr<Color> color) : Shape(color) {}
    std::string getName() override {
        return "Circle";
    }
    std::string getShape() override {
        return color_->getColor() + " " + getName();
    }
};

int main() {
    std::shared_ptr<RedColor> red = std::make_shared<RedColor>();
    std::shared_ptr<GreenColor> green = std::make_shared<GreenColor>();
    std::shared_ptr<BlueColor> blue = std::make_shared<BlueColor>();

    std::unique_ptr<Shape> triangleRed = std::make_unique<Triangle>(red);
    std::unique_ptr<Shape> squareGreen = std::make_unique<Square>(green);
    std::unique_ptr<Shape> circleBlue = std::make_unique<Circle>(blue);

    std::cout << triangleRed->getShape().c_str() << std::endl; // Output: Red Triangle
    std::cout << squareGreen->getShape().c_str() << std::endl; // Output: Green Square
    std::cout << circleBlue->getShape().c_str()  << std::endl; // Output: Blue Circle

    return 0;
}
