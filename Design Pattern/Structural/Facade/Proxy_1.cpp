/*
The Proxy Design Pattern is a structural design pattern that provides a surrogate or placeholder for another object to control access to it.
The Proxy Design Pattern is useful when we want to provide controlled access to an object, either because it is expensive to create or because
we want to add additional functionality to the object's behavior. Instead of accessing the object directly, clients interact with a proxy object
that forwards requests to the real object as needed.

There are several variations of the Proxy Design Pattern, including:

1. Remote Proxy: This pattern is used when the real object is located in a remote location, and the proxy acts as a local representative of the real object.
2. Virtual Proxy: This pattern is used when the real object is expensive to create or initialize, and the proxy is used to delay its creation until it is actually needed.
3. Protection Proxy: This pattern is used when we want to control access to the real object by checking permissions or enforcing other security measures.
4. Smart Proxy: This pattern is used when we want to add additional functionality to the real object's behavior, such as caching or logging.

Overall, the Proxy Design Pattern provides a flexible and powerful way to control access to objects and add additional functionality to their behavior as needed.

*/

/* sample of Vitrual Proxy*/

#include <iostream>
#include <string>

class Document {
public:
    Document(int id) : id_(id) {
        // Load data from database
        data_ = loadDataFromDatabase(id_);
    }

    std::string getData() {
        return data_;
    }

private:
    int id_;
    std::string data_;

    std::string loadDataFromDatabase(int id) {
        // Simulate loading data from database
        return "Data for document with ID " + std::to_string(id);
    }
};

class DocumentProxy {
public:
    DocumentProxy(int id) : id_(id), document_(nullptr) {}

    std::string getData() {
        if (document_ == nullptr) {
            document_ = new Document(id_);
        }
        return document_->getData();
    }

private:
    int id_;
    Document* document_;
};

int main() {
    // Create a proxy object
    DocumentProxy proxy(123);

    // Call the getData() method on the proxy object
    std::cout << proxy.getData() << std::endl;

    return 0;
}
