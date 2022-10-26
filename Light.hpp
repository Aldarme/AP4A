#ifndef LIGHT_H
#define LIGHT_H

#include "Sensor.hpp"
#include <iostream>

/*
author: Tom PALLEAU
date: 10/1/2022
licence: free
class: Light
*/

class Light: public Sensor<bool>
{
    public:
    Light();
    bool getData();
};

#endif // LIGHT_H