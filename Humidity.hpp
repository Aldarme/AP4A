#ifndef HUMIDITY_H
#define HUMIDITY_H

#include <iostream>
#include <cstdio>
#include "Sensor.hpp"

class Humidity : public Sensor<float>
{
    protected :
        float aleaGenVal() {
            return min + (static_cast<float>(rand()) * static_cast<float>(max - min) / RAND_MAX); // aleagenval pour float entre le min et max
        };


    public : 
        Humidity(){
            min = 0;
            max = 100;
            (*this).value = aleaGenVal();
        }

};

#endif