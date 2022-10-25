#ifndef HUMIDITY_H
#define HUMIDITY_H

#include "Sensor.hpp"

/**
* @class DataHumidity
* @brief Declaration de la classe DataHumidity
*/
class DataHumidity: public Sensor<float>
{
public:
    
    float getVal();

    float aleaGenVal(float minValue, float maxValue);
};

#endif