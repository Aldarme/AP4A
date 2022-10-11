/** 
 * @author SCHERRER Guillaume
 * @file Humidity.cpp
 * @date 25/09/2022
 * @brief definiton ds corps des méthodes de Humidity.hpp
 *  
*/

// génériques:
#include <iostream>
#include <stdlib.h>     /* srand, rand */

// classe:
#include "Sensor.hpp"
#include "Humidity.hpp"

Humidity::Humidity(float min, float max) // constructor
{
    m_Humidity_min = min;
    m_Humidity_max = max;
}

Humidity::~Humidity() {}    // destructor



float Humidity::aleaSensorVal()    //
{
    float HumidityVal  =  Sensor::aleaGenVal(m_Humidity_min, m_Humidity_max); // writes to m_data

   return HumidityVal; // 
}


float Humidity::getData()
{
    return Sensor::getData();
}


