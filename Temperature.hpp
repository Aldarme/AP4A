#ifndef TEMPERATURE_H
#define TEMPERATURE_H

/*
author: Tom PALLEAU
date: 10/1/2022
licence: free
class: Server
*/

#include "Sensor.hpp"
#include <iostream>

class Temperature: public Sensor<float>
{
    public:
    Temperature();
};

#endif // TEMPERATURE_H