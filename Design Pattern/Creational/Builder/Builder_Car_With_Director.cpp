
/*

The Builder Design Pattern is a creational design pattern that allows us to construct complex objects step by step. This pattern separates the construction of
an object from its representation, allowing us to produce different types and representations of an object using the same construction process. The Builder
Pattern provides a way to create complex objects by providing a step-by-step construction process, which helps us decouple our code by separating the creation
of an object from its representation. This pattern is commonly used in software systems that need to create complex objects with many optional parameters or
configurations, such as databases or user interfaces.


*/

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
   virtual ~CarBuilder() {}

   virtual void buildMake() {}
   virtual void buildModel() {}
   virtual void buildYear() {}
   virtual void buildColor() {}

   Car getCar() { 
       return car; 
   }

protected:
   Car car; 
};

class MustangBuilder : public CarBuilder {
public:
   void buildMake() override { 
       car.setMake("Ford"); 
   }

   void buildModel() override { 
       car.setModel("Mustang"); 
   }

   void buildYear() override { 
       car.setYear(1967); 
   }

   void buildColor() override { 
       car.setColor("red"); 
   }
};

class CamaroBuilder : public CarBuilder {
public:
   void buildMake() override { 
       car.setMake("Chevrolet"); 
   }

   void buildModel() override { 
       car.setModel("Camaro"); 
   }

   void buildYear() override { 
       car.setYear(1970);  
  }

  void buildColor() override {  
      car.setColor("blue");  
  }
};

class Director {
public:
  Director(CarBuilder* builder)
      : builder(builder) {}

  Car constructCar()
  {
      builder->buildMake();
      builder->buildModel();
      builder->buildYear();
      builder->buildColor();

      return builder->getCar();
  }

private:
  CarBuilder* builder;
};

int main()
{
  MustangBuilder mustang_builder;
  CamaroBuilder camaro_builder;

  Director director1(&mustang_builder);
  Director director2(&camaro_builder);

  // Build a red Ford Mustang from 1967
  Car mustang = director1.constructCar();

  // Build a blue Chevrolet Camaro from 1970
  Car camaro = director2.constructCar();

  // Print the descriptions of the cars
  std::cout << mustang.getDescription() << "\n";
  std::cout << camaro.getDescription() << "\n";

 return EXIT_SUCCESS;
}