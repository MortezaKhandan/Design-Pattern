/* Simple*/
/*
The Template Design Pattern is a behavioral design pattern that defines the skeleton of an algorithm in the superclass but lets subclasses override specific
steps of the algorithm without changing its structure. In this pattern, an abstract class exposes defined way(s)/template(s) to execute its methods, and its
subclasses can override the method implementation as needed. The Template Method defines a skeleton of an algorithm in an operation and defers some steps to
subclasses.
This pattern helps us decouple our code by allowing us to define a common structure for algorithms while still allowing individual steps to be customized by
subclasses.
The Template Method is particularly useful when we need to implement complex algorithms that have similar structures but different implementations for certain
steps.
This pattern also makes it easier to add new types of algorithms without having to modify existing code. Home builders use the Template Method when building
houses, where they follow a set of predefined steps but customize certain aspects based on customer preferences or local building codes.

*/
#include <iostream>
#include <string>
#include <vector>

// Abstract Book class
class Book {
public:
    Book(const std::string& title, const std::string& author) : title_(title), author_(author) {}
    virtual void generateBook() final {
        selectTitle();
        selectAuthor();
        selectContent();
        selectCoverDesign();
        if (isPaperback()) {
            bindPages();
        }
        publish();
    }
    virtual ~Book() {}
private:
    // Common steps for generating books
    void selectTitle() {
        std::cout << "Title: " << title_ << std::endl;
    }
    void selectAuthor() {
        std::cout << "Author: " << author_ << std::endl;
    }
    void publish() {
        std::cout << "Book published." << std::endl;
    }
    // Abstract methods to be implemented by subclasses
    virtual void selectContent() = 0;
    virtual void selectCoverDesign() = 0;
    virtual bool isPaperback() = 0;
    virtual void bindPages() {}
protected:
    std::string title_;
    std::string author_;
};

// Concrete Paper Book class
class PaperBook : public Book {
public:
    PaperBook(const std::string& title, const std::string& author) : Book(title, author) {}
    bool isPaperback() {
        return true;
    }
    void bindPages() {
        std::cout << "Pages bound." << std::endl;
    }
    void selectContent() {
        std::cout << "Content selected for paper book." << std::endl;
    }
    void selectCoverDesign() {
        std::cout << "Cover design selected for paper book." << std::endl;
    }
};

// Concrete E-Book class
class EBook : public Book {
public:
    EBook(const std::string& title, const std::string& author) : Book(title, author) {}
    bool isPaperback() {
        return false;
    }
    void selectContent() {
        std::cout << "Content selected for e-book." << std::endl;
    }
    void selectCoverDesign() {
        std::cout << "Cover design selected for e-book." << std::endl;
    }
};

int main() {
    std::vector<std::unique_ptr<Book>> books;
    books.emplace_back(std::make_unique<PaperBook>("The Great Gatsby", "F. Scott Fitzgerald"));
    books.emplace_back(std::make_unique<EBook>("Pride and Prejudice", "Jane Austen"));

    for (const auto& book : books) {
        book->generateBook();
        std::cout << std::endl;
    }

    return 0;
}
