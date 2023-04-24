/*
The Null Object Design Pattern is a design pattern that simplifies the use of dependencies that can be undefined.
This pattern replaces the check of a null object instance with a null object that reflects a do-nothing relationship.
The Null Object Pattern provides a way to handle null values in our code without having to write explicit checks for them.
Instead of checking for null values, we can use a Null Object that provides default behavior in case data is not available.
This pattern helps us decouple our code by allowing us to provide default behavior for missing objects without having to modify
the underlying classes. The Null Object Pattern is commonly used in software systems that need to handle missing or optional data,
such as databases or user interfaces.


*/


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Emp {
protected:
    string name;
public:
    virtual bool isNull() = 0;
    virtual string getName() = 0;
};

class Coder : public Emp {
public:
    Coder(string name) {
        this->name = name;
    }
    string getName() override {
        return name;
    }
    bool isNull() override {
        return false;
    }
};

class NoClient : public Emp {
public:
    string getName() override {
        return "Not Available";
    }
    bool isNull() override {
        return true;
    }
};

class EmpData {
public:
    static vector<string> names;
    static Emp* getClient(string name) {
        if (find(names.begin(), names.end(), name) != names.end()) {
            return new Coder(name);
        }
        return new NoClient();
    }
};

vector<string> EmpData::names = {"Emma", "Della", "Olivia"};

int main() {
    Emp* emp1 = EmpData::getClient("Emma");
    Emp* emp2 = EmpData::getClient("Della");
    Emp* emp3 = EmpData::getClient("Olivia");
    Emp* emp4 = EmpData::getClient("Liam");

    cout << emp1->getName() << endl;
    cout << emp2->getName() << endl;
    cout << emp3->getName() << endl;
    cout << emp4->getName() << endl;

    delete emp1;
    delete emp2;
    delete emp3;
    delete emp4;

    return 0;
}
