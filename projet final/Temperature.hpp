#ifndef TEMPERATURE_H
#define TEMPERATURE_H


#include "Sensor.hpp"

class Temperature: public Sensor<float>
{
public:
    
    float getVal();
    float aleaGenVal(float minValue, float maxValue);
};

#endif 