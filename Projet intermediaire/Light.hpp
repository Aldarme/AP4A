/**
 * @author Tontsa apala frank
 * @file Light.hpp
 * @date 25/09/2022
 * @brief Light sensor
 */
#include <iostream>
#include "Sensor.hpp"
#ifndef LIGHT_H
#define LIGHT_H
class Light : public Sensor{
     public : Light():Sensor(){};

    public : Light(const Light& L);

~Light();
};


#endif //LIGHT_H
