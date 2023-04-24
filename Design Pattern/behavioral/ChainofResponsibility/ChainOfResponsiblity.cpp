/*
The Chain of Responsibility Design Pattern in C++ is a behavioral design pattern that allows passing a request along a chain of potential handlers until one of them handles the request.
This pattern allows multiple objects to handle the request without coupling the sender class to the concrete classes of the receivers. The Chain of Responsibility Design Pattern can be
implemented using a "next" pointer in the base class, which delegates to the next object in the chain. This pattern is useful for creating loosely coupled systems and can be used to
process commands or queries.

*/

#include <iostream>
#include <memory>

class Handler {
public:
    virtual ~Handler() {}
  friend  class ConcreteHandler1;
  friend  class  ConcreteHandler2;
  friend  class  ConcreteHandler3;

    void setNext(std::unique_ptr<Handler> next) {
        _next = std::move(next);
    }

    virtual void handleRequest(int request) {
        if (_next != nullptr) {
            _next->handleRequest(request);
        }
    }

private:
    std::unique_ptr<Handler> _next;
};

class ConcreteHandler1 : public Handler {
public:
    void handleRequest(int request) override {
        if (request >= 0 && request < 10) {
            std::cout << "ConcreteHandler1 handled the request.\n";
        } else if (_next != nullptr) {
            _next->handleRequest(request);
        }
    }
};

class ConcreteHandler2 : public Handler {
public:
    void handleRequest(int request) override {
        if (request >= 10 && request < 20) {
            std::cout << "ConcreteHandler2 handled the request.\n";
        } else if (_next != nullptr) {
            _next->handleRequest(request);
        }
    }
};

class ConcreteHandler3 : public Handler {
public:
    void handleRequest(int request) override {
        if (request >= 20 && request < 30) {
            std::cout << "ConcreteHandler3 handled the request.\n";
        } else if (_next != nullptr) {
            _next->handleRequest(request);
        }
    }
};

int main() {

   // Create the chain of handlers
   auto handler1 = std::make_unique<ConcreteHandler1>();
   auto handler2 = std::make_unique<ConcreteHandler2>();
   auto handler3 = std::make_unique<ConcreteHandler3>();

   handler1->setNext(std::move(handler2));
   handler2->setNext(std::move(handler3));

   // Handle requests
   handler1->handleRequest(5); // Output: ConcreteHandler1 handled the request.
   handler1->handleRequest(15); // Output: ConcreteHandler2 handled the request.
   handler1->handleRequest(25); // Output: ConcreteHandler3 handled the request.
   
   return 0;
}