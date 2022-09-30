#ifndef HUMIDITY_H
#define HUMIDITY_H

#include "Sensor.hpp"

class Humidity: public Sensor
{
private:
    int value; 

public:
    Humidity();
    Humidity(const Humidity& h); 
    Humidity& operator=(const Humidity& h); 
    Humidity& operator=(float h); 
    ~Humidity();


    int aleaGenValue() override; 

};


#endif // HUMIDITY_H