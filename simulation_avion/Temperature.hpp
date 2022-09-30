#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include "Sensor.hpp"

class Temperature:public Sensor
{
private:
    int value; 

public:

    Temperature();
    Temperature(const Temperature& t); 
    Temperature& operator=(const Temperature& t); 
    Temperature& operator=(float t);
    ~Temperature();

    int aleaGenValue() override; 

};

#endif // TEMPERATURE_H