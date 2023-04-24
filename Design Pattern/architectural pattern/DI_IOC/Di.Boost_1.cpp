#include <iostream>
#include <string>
#include <memory>
#include <boost/di.hpp>

namespace di = boost::di;

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
    Greeting(std::shared_ptr<ILogger> logger) : logger_(logger) {}

    void SayHello(const std::string& name) {
        logger_->Log("Saying hello to " + name);
        std::cout << "Hello, " << name << "!" << std::endl;
    }

private:
    std::shared_ptr<ILogger> logger_;
};

int main() {
    auto injector = di::make_injector(
        di::bind<ILogger>().to<ConsoleLogger>()
    );
    auto greeting = injector.create<Greeting>();
    greeting.SayHello("Alice");
    greeting.SayHello("Bob");
    return 0;
}
