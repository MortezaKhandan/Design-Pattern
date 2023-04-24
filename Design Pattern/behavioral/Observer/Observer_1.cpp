/*

The Observer Design Pattern is useful when we are interested in the state of an object and want to get notified whenever there is any change.
It establishes a one-to-many relationship between objects, where multiple observers are notified automatically of any state changes in the subject.
The observer pattern is particularly useful when we need to maintain consistency between related objects without tightly coupling them together.
By separating the observer from the subject, it makes it easier to add new observers or remove existing ones without affecting other parts of the
codebase.
This pattern is commonly used in event-driven systems, user interfaces, and distributed systems where changes in one part of the system need to be
propagated to other parts

Here are some reasons why you might want to use the Observer design pattern:

1. Decoupling of objects: The Observer pattern decouples the subject (the object being observed) from its observers,
so that changes to one object do not require changes to other objects that depend on it.

2. Flexibility and modifiability: The Observer pattern allows you to add or remove observers at runtime, without affecting
the subject or other observers. This makes it easier to modify or extend the behavior of the system.

3. Loose coupling: The Observer pattern promotes loose coupling between objects, since the subject and observers interact
through well-defined interfaces and do not have direct knowledge of each other's implementation details.

4. Testability: The Observer pattern makes it easier to test individual objects in isolation, since the subject and observers
can be tested independently.

5. Reusability: The Observer pattern enables the reuse of subject and observer objects across different contexts and applications,
which can save time and effort in software development.

Overall, the Observer pattern can help you write more flexible, maintainable, and loosely coupled code, by separating concerns and
enabling objects to react to changes in state without having direct knowledge of each other's implementation.

*/

#include <iostream>
#include <vector>

using namespace std;

// Abstract base class for Observers
class Observer {
public:
    virtual void update(int data) = 0;
};

// Concrete implementation of an Observer
class ConcreteObserver : public Observer {
public:
    ConcreteObserver(string name) : m_name(name) {}
    void update(int data) override {
        cout << m_name.c_str() << " received update with data: " << data << endl;
    }
private:
    string m_name;
};

// Abstract base class for Subjects
class Subject {
public:
    void attach(Observer* observer) {
        m_observers.push_back(observer);
    }
    void detach(Observer* observer) {
        m_observers.erase(remove(m_observers.begin(), m_observers.end(), observer), m_observers.end());
    }
    void notify(int data) {
        for (Observer* observer : m_observers) {
            observer->update(data);
        }
    }
private:
    vector<Observer*> m_observers;
};

// Concrete implementation of a Subject
class ConcreteSubject : public Subject {
public:
    void setData(int data) {
        m_data = data;
        notify(m_data);
    }
private:
    int m_data;
};

// Usage example
int main() {
    ConcreteObserver observer1("Observer 1");
    ConcreteObserver observer2("Observer 2");

    ConcreteSubject subject;
    subject.attach(&observer1);
    subject.attach(&observer2);

    subject.setData(42);

    subject.detach(&observer2);

    subject.setData(123);

    return 0;
}
