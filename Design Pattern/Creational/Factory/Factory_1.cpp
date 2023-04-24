
/*
The Factory Design Pattern is a creational design pattern that provides an interface for creating objects in a superclass,
but allows subclasses to alter the type of objects that will be created. In this pattern, we create objects without exposing
the creation logic to the client and refer to newly created objects using a common interface. The factory method pattern is
used when we have a superclass with multiple subclasses and based on input, we need to return one of the subclasses.
This pattern helps us decouple our code by allowing us to create objects without having to know their specific class names
or implementation details. It also makes it easier to add new types of objects without having to modify existing code.

There are several benefits to using the factory design pattern, including:

1. Encapsulation: The factory pattern encapsulates the creation of objects in a separate class or method.
This makes it easier to manage and modify the creation process without affecting the rest of the code.

2. Abstraction: The factory pattern allows you to work with objects at a higher level of abstraction.
Instead of dealing with the specifics of how objects are created, you can simply request an object from the factory and let it handle the details.

3. Flexibility: The factory pattern makes it easy to add new types of objects without modifying the existing code.
You simply create a new subclass of the product class and update the factory to create objects of that type.

4. Testability: The factory pattern makes it easier to write unit tests for your code. Because the creation of objects
is encapsulated in the factory, you can create mock objects or stubs to simulate different types of objects and test the code that uses them.

5. Decoupling: The factory pattern decouples the client code from the concrete implementations of the objects. This means
that you can change the concrete implementations of the objects without affecting the client code, as long as they still conform to the same interface.

*/

#include <iostream>
using namespace std;

// Abstract product class
class FingerprintDevice {
public:
    virtual void authenticate() = 0;
};

// Concrete product classes
class WindowsFingerprintDevice : public FingerprintDevice {
public:
    void authenticate() {
        cout << "Authenticating with Windows fingerprint device..." << endl;
        // Windows fingerprint device specific authentication code
    }
};

class LinuxFingerprintDevice : public FingerprintDevice {
public:
    void authenticate() {
        cout << "Authenticating with Linux fingerprint device..." << endl;
        // Linux fingerprint device specific authentication code
    }
};

// Factory class
class FingerprintDeviceFactory {
public:
    FingerprintDevice* createDevice(string platform) {
        if (platform == "Windows") {
            return new WindowsFingerprintDevice();
        }
        else if (platform == "Linux") {
            return new LinuxFingerprintDevice();
        }
        else {
            return NULL;
        }
    }
};

int main() {
    // Create factory object
    FingerprintDeviceFactory* factory = new FingerprintDeviceFactory();

    // Create Windows fingerprint device object
    FingerprintDevice* windowsDevice = factory->createDevice("Windows");
    windowsDevice->authenticate();

    // Create Linux fingerprint device object
    FingerprintDevice* linuxDevice = factory->createDevice("Linux");
    linuxDevice->authenticate();

    // Clean up memory
    delete windowsDevice;
    delete linuxDevice;
    delete factory;

    return 0;
}

