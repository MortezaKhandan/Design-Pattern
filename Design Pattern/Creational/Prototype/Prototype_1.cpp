#include <iostream>
#include <string>
#include <memory>

class Car
{
public:
    virtual ~Car() {}

    virtual std::unique_ptr<Car> clone() = 0;

    virtual void print() const = 0;

    // Getters and setters for the car properties
    virtual std::string getBrand() const = 0;
    virtual void setBrand(const std::string& brand) = 0;

    virtual std::string getModel() const = 0;
    virtual void setModel(const std::string& model) = 0;

    virtual int getYear() const = 0;
    virtual void setYear(int year) = 0;

    virtual int getMileage() const = 0;
    virtual void setMileage(int mileage) = 0;

    virtual std::string getColor() const = 0;
    virtual void setColor(const std::string& color) = 0;

    virtual std::string getVIN() const = 0;
    virtual void setVIN(const std::string& vin) = 0;
};

class Sedan : public Car
{
public:
    std::unique_ptr<Car> clone() override
    {
        return std::make_unique<Sedan>(*this);
    }

    void print() const override
    {
        std::cout << "Sedan - Brand: " << m_brand
                  << ", Model: " << m_model
                  << ", Year: " << m_year
                  << ", Mileage: " << m_mileage
                  << ", Color: " << m_color
                  << ", VIN: " << m_vin
                  << std::endl;
    }

    // Getters and setters for the car properties
    std::string getBrand() const override { return m_brand; }
    void setBrand(const std::string& brand) override { m_brand = brand; }

    std::string getModel() const override { return m_model; }
    void setModel(const std::string& model) override { m_model = model; }

    int getYear() const override { return m_year; }
    void setYear(int year) override { m_year = year; }

    int getMileage() const override { return m_mileage; }
    void setMileage(int mileage) override { m_mileage = mileage; }

    std::string getColor() const override { return m_color; }
    void setColor(const std::string& color) override { m_color = color; }

    std::string getVIN() const override { return m_vin; }
    void setVIN(const std::string& vin) override { m_vin = vin; }

private:
    std::string m_brand;
    std::string m_model;
    int m_year;
    int m_mileage;
    std::string m_color;
    std::string m_vin;
};

int main()
{
    // Create a prototype Sedan object
    std::unique_ptr<Sedan> sedanPrototype = std::make_unique<Sedan>();
    sedanPrototype->setBrand("Toyota");
    sedanPrototype->setModel("Camry");
    sedanPrototype->setYear(2021);
    sedanPrototype->setMileage(0);
    sedanPrototype->setColor("White"); // or we can set it empty as default 
    sedanPrototype->setVIN("ABC123");

    // Clone the prototype and customize the clone
    std::unique_ptr<Car> myCar = sedanPrototype->clone();
    myCar->setMileage(1000);
    myCar->setColor("Red");

    // Print the prototype
    std::cout << "Prototype Sedan:" << std::endl;
    sedanPrototype->print();
    // Print the customized clone
   std::cout << "Customized Sedan:" << std::endl;
   myCar->print();

   return 0;
}
