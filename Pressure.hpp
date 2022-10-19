#ifndef PRESSURE_H
#define PRESSURE_H

/*
author: Tom PALLEAU
date: 10/1/2022
licence: free
class: Package
*/

#include "Sensor.hpp"
#include <iostream>

class Pressure: public Sensor<int>
{
    public:
    Pressure();
    int getData();
};

#endif // LIGHT_H