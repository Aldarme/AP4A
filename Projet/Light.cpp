/**
* @author Alan HERVE
* @file Light.cpp
* @date 01/10/2022
* @brief Child class of Sensor
**/

#ifndef LIGHT_CPP
#define LIGHT_CPP

#include "Light.hpp"


void Light::next()
{
    this->value = Sensor<bool>::aleaGenVal();
}

#endif
