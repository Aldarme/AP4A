/** 
 * @author SCHERRER Guillaume
 * @file Temperature.cpp
 * @date 25/09/2022
 * @brief definiton ds corps des méthodes de Temperature.hpp
 *  
*/

// génériques:
#include <iostream>
#include <stdlib.h>     /* srand, rand */

// classe:
#include "Sensor.hpp"
#include "Temperature.hpp"

Temperature::Temperature(float min, float max) // constructor
{
    m_temperature_min = min;
    m_temperature_max = max;
}

Temperature::~Temperature() {}    // destructor



float Temperature::aleaSensorVal()    //
{
    float TemperatureVal  =  Sensor::aleaGenVal(m_temperature_min, m_temperature_max);

   return TemperatureVal; // 
}


float Temperature::getData()
{
    return Sensor::getData();
}


