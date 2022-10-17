#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <iostream>
#include <cstdio>
#include "Sensor.hpp"


class Temperature : public Sensor<float>
{
    protected :
        float aleaGenVal() 
        {
            return min + (static_cast<float>(rand()) * static_cast<float>(max - min) / RAND_MAX);
        };

    
    public : 
        Temperature()
        {
            min = 0;
            max = 50;
            (*this).value = aleaGenVal();
        };

};

#endif