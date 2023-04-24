#include <iostream>
#include <memory>
#include <string>
#include <boost/di.hpp>

namespace di = boost::di;

// View interface
class IView {
public:
    virtual void ShowGreeting(const std::string& greeting) = 0;
};

// Console implementation of the view interface
class ConsoleView : public IView {
public:
    void ShowGreeting(const std::string& greeting) override {
        std::cout << "Greeting: " << greeting << std::endl;
    }
};

// Model interface
class IModel {
public:
    virtual std::string GetGreeting(const std::string& name) = 0;
};

// Model implementation
class Model : public IModel {
public:
    std::string GetGreeting(const std::string& name) override {
        return "Hello, " + name + "!";
    }
};

// Presenter
class Presenter {
public:
    Presenter(std::shared_ptr<IView> view, std::shared_ptr<IModel> model)
        : view_(view), model_(model) {}

    void OnGreet(const std::string& name) {
        std::string greeting = model_->GetGreeting(name);
        view_->ShowGreeting(greeting);
    }

private:
    std::shared_ptr<IView> view_;
    std::shared_ptr<IModel> model_;
};

int main() {
    auto injector = di::make_injector(
        di::bind<IView>().to<ConsoleView>(),
        di::bind<IModel>().to<Model>()
    );

    auto presenter = injector.create<Presenter>();
    presenter.OnGreet("Alice");
    presenter.OnGreet("Bob");

    return 0;
}
