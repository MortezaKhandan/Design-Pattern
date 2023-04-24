#include <iostream>
#include <string>

class ILogger {
public:
    virtual void Log(const std::string& message) = 0;
    virtual ~ILogger() {}
};

class ConsoleLogger : public ILogger {
public:
    void Log(const std::string& message) override {
        std::cout << "Log: " << message << std::endl;
    }
};

class Greeting {
public:
    Greeting(ILogger* logger) : logger_(logger) {}

    void SayHello(const std::string& name) {
        logger_->Log("Saying hello to " + name);
        std::cout << "Hello, " << name << "!" << std::endl;
    }

private:
    ILogger* logger_;
};

int main() {
    ConsoleLogger console_logger;
    Greeting greeting(&console_logger);
    greeting.SayHello("Alice");
    greeting.SayHello("Bob");
    return 0;
}
