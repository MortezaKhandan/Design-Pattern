
/* In this example, the Model class represents the business logic and data storage, the View class represents the UI,
   and the Presenter class acts as an intermediary between the two, handling user input and updating the view with data
   from the model. The main function creates instances of all three components and connects them together by passing 
   references to the Model and View objects to the Presenter constructor. */

// Model
class Model {
public:
    void set_data(const std::string& data) {
        data_ = data;
    }

    const std::string& get_data() const {
        return data_;
    }

private:
    std::string data_;
};

// View
class View {
public:
    void show_data(const std::string& data) {
        std::cout << "Data: " << data << std::endl;
    }

    std::string get_input() {
        std::string input;
        std::cout << "Enter data: ";
        std::getline(std::cin, input);
        return input;
    }
};

// Presenter
class Presenter {
public:
    Presenter(Model& model, View& view)
        : model_(model), view_(view) {}

    void update_data() {
        std::string data = view_.get_input();
        model_.set_data(data);
    }

    void present_data() {
        std::string data = model_.get_data();
        view_.show_data(data);
    }

private:
    Model& model_;
    View& view_;
};

int main() {
    Model model;
    View view;
    Presenter presenter(model, view);

    presenter.update_data();
    presenter.present_data();

    return 0;
}
