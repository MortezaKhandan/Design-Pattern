#include <iostream>
#include <string>

class Logger {
public:
    void Log(const std::string& message) {
        std::cout << "Log: " << message << std::endl;
    }
};

class Greeting {
public:
    void SayHello(const std::string& name) {
        logger_.Log("Saying hello to " + name);
        std::cout << "Hello, " << name << "!" << std::endl;
    }

private:
    Logger logger_;
};

int main() {
    Greeting greeting;
    greeting.SayHello("Alice");
    greeting.SayHello("Bob");
    return 0;
}
