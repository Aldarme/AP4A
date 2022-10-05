/**@author Alan_HERVE
*@file Humditiy.cpp
*@date 05/10/2022
*@brief child class of Sensor
**/

#ifndef HUMIDITY_CPP
#define HUMIDITY_CPP

#include "Humidity.hpp"


void Humidity::next()
{
    this->value = Sensor<float>::aleaGenVal();
}

#endif
