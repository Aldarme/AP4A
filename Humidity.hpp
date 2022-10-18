#ifndef HUMIDITY_H
#define HUMIDITY_H


#include "Sensor.hpp"

class Humidity : public Sensor<float>{
   private:
   public:

        Humidity(){
           
        this->type = "humidity";
        this->value = Sensor<float>::getData();
        }; 
        Humidity(const Humidity&); 
        Humidity &operator=(const Humidity&); 
        ~Humidity(); 
    
};
#endif 