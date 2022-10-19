#ifndef HUMIDITY_H
#define HUMIDITY_H

/*
author: Tom PALLEAU
date: 10/1/2022
licence: free
class: Humidity
*/

#include "Sensor.hpp"

class Humidity: public Sensor<float>
{
    public:
    Humidity();
};

#endif // HUMIDITY_H