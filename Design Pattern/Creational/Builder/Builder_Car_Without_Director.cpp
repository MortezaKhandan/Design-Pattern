
#include <iostream>
#include <string>

class Car {
public:
    void setMake(const std::string& make) {
        m_make = make;
    }
    
    void setModel(const std::string& model) {
        m_model = model;
    }
    
    void setYear(int year) {
        m_year = year;
    }
    
    void setColor(const std::string& color) {
        m_color = color;
    }
    
    std::string getDescription() const {
        return "This is a " + std::to_string(m_year) + " " + m_make + " " + m_model + " in " + m_color + ".";
    }

private:
    std::string m_make;
    std::string m_model;
    int m_year = 0;
    std::string m_color;
};

class CarBuilder {
public:
    CarBuilder& setMake(const std::string& make) {
        car.setMake(make);
        return *this;
    }
    
    CarBuilder& setModel(const std::string& model) {
        car.setModel(model);
        return *this;
    }
    
    CarBuilder& setYear(int year) {
        car.setYear(year);
        return *this;
    }
    
    CarBuilder& setColor(const std::string& color) { 
        car.setColor(color);
        return *this; 
   }

   Car build() { 
       return car; 
   }

private:
   Car car; 
};

int main() {
   CarBuilder builder;

   // Build a red Ford Mustang from 1967
   Car mustang = builder.setMake("Ford")
                       .setModel("Mustang")
                       .setYear(1967)
                       .setColor("red")
                       .build();

   // Build a blue Chevrolet Camaro from 1970
   Car camaro = builder.setMake("Chevrolet")
                       .setModel("Camaro")
                       .setYear(1970)
                       .setColor("blue")
                       .build();

   // Print the descriptions of the cars
   std::cout << mustang.getDescription() << "\n";
   std::cout << camaro.getDescription() << "\n";

   return 0;
}