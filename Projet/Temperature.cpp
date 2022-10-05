/**
* @author Alan HERVE
* @file Temperature.cpp
* @date 01/10/2022
* @brief Child class of Sensor
**/


#ifndef TEMPERATURE_CPP
#define TEMPERATURE_CPP

#include "Temperature.hpp"


void Temperature::next()
{
    this->value = Sensor<int>::aleaGenVal();
}

#endif
