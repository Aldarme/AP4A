#ifndef LIGHT_H
#define LIGHT_H
#include "Sensor.hpp"


class light: public Sensor<bool>
{
public:
    
    bool getVal();
    bool aleaGenVal(bool minValue,bool maxValue);
};

#endif 