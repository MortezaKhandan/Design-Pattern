#include <iostream>
#include <memory>

class Device {
public:
    virtual void connect() = 0;
};

class Sensor : public Device {
public:
    void connect() override {
        std::cout << "Connecting sensor via I2C protocol..." << std::endl;
    }
};

class Printer : public Device {
public:
    void connect() override {
        std::cout << "Connecting printer via Bluetooth..." << std::endl;
    }
};

class DeviceFactory {
public:
    static std::unique_ptr<Device> createDevice(const std::string& type) {
        if ( type == "sensor" ) {
            return std::make_unique<Sensor>();
        }
        else if ( type == "printer" ) {
            return std::make_unique<Printer>();
        }
        else {
            throw std::invalid_argument("Unknown device type: " + type);
        }
    }
};

int main() {
    // Use factory to create devices
    auto sensor = DeviceFactory::createDevice("sensor");
    sensor->connect();

    auto printer = DeviceFactory::createDevice("printer");
    printer->connect();

    return 0;
}
