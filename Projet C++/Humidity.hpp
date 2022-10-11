#ifndef HUMIDITY_H
#define HUMIDITY_H


#include "Sensor.hpp"

class Humidity : public Sensor{
   private:
   public:
    void sen();
        Humidity(); 
        Humidity(const Humidity&); 
        Humidity &operator=(const Humidity&); 
        ~Humidity(); 
    
};
#endif 