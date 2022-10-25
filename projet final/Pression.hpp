#ifndef PRESSION_H
#define PRESSION_H


#include "Sensor.hpp"
#include <iostream>


class Pressure: public Sensor<int>
{
public:
   
    int getVal();
    int aleaGenVal(int minValue, int maxValue);   
};


#endif