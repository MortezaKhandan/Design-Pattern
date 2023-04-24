/*
In this example, we created three interfaces for Model, View, and Presenter. Then we implemented two classes for Model and View, and one class for Presenter.
 We also made sure that all the dependencies are passed through their respective interfaces.
Finally, using Boost DI, we created an injector that provides the necessary dependencies to create the Presenter, and we use the Presenter to perform the logic.
*/


#include <iostream>
#include <memory>
#include <string>
#include <boost/di.hpp>

namespace di = boost::di;

// Model interface
class IModel {
public:
    virtual void set_data(const std::string& data) = 0;
    virtual const std::string& get_data() const = 0;
    virtual ~IModel() {}
};

// Model implementation
class Model : public IModel {
public:
    void set_data(const std::string& data) override {
        data_ = data;
    }

    const std::string& get_data() const override {
        return data_;
    }

private:
    std::string data_;
};

// View interface
class IView {
public:
    virtual void show_data(const std::string& data) = 0;
    virtual std::string get_input() = 0;
    virtual ~IView() {}
};

// Console implementation of the view interface
class ConsoleView : public IView {
public:
    void show_data(const std::string& data) override {
        std::cout << "Data: " << data << std::endl;
    }

    std::string get_input() override {
        std::string input;
        std::cout << "Enter data: ";
        std::getline(std::cin, input);
        return input;
    }
};

// Presenter interface
class IPresenter {
public:
    virtual void update_data() = 0;
    virtual void present_data() = 0;
    virtual ~IPresenter() {}
};

// Presenter implementation
class Presenter : public IPresenter {
public:
    Presenter(std::shared_ptr<IModel> model, std::shared_ptr<IView> view)
        : model_(model), view_(view) {}

    void update_data() override {
        std::string data = view_->get_input();
        model_->set_data(data);
    }

    void present_data() override {
        std::string data = model_->get_data();
        view_->show_data(data);
    }

private:
    std::shared_ptr<IModel> model_;
    std::shared_ptr<IView> view_;
};

int main() {
    auto injector = di::make_injector(
        di::bind<IModel>().to<Model>(),
        di::bind<IView>().to<ConsoleView>(),
        di::bind<IPresenter>().to<Presenter>()
    );

    auto presenter = injector.create<std::shared_ptr<IPresenter>>();
    presenter->update_data();
    presenter->present_data();

    return 0;
}
