/**
 * @author Erhart Eliott
 * @file Sensor.cpp
 * @date 03/10/2022
 * @brief 
 */

#include "Sensor.hpp"
#include <cstdlib>
#include <ctime>

Sensor Sensor::aleaGenVal(int min, int max)
{
    srand((int)time(0));
    aleaVal = rand()%(max-min + 1) + min;
    return *this;
}

Sensor Humidity::getVal()
{
    return aleaGenVal(0, 20);
}

Sensor Light::getVal()
{
    return aleaGenVal(0, 2);
}

Sensor Pressure::getVal()
{
    return aleaGenVal(0, 50);
}

Sensor Temperature::getVal()
{
    return aleaGenVal(0, 30);
}

