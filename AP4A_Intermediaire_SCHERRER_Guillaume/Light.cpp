/** 
 * @author SCHERRER Guillaume
 * @file Server.cpp
 * @date 25/09/2022
 * @brief definiton ds corps des méthodes de Light.hpp
 *  
*/

// génériques:
#include <iostream>
#include <stdlib.h>     /* srand, rand */

// classe:
#include "Sensor.hpp"
#include "Light.hpp"

Light::Light(float min, float max) // constructor
{
    m_Light_min = min;
    m_Light_max = max;
}

Light::~Light() {}    // destructor



float Light::aleaSensorVal()    //
{
    float LightVal  =  Sensor::aleaGenVal(m_Light_min, m_Light_max); // writes to m_data

   return LightVal; // 
}


float Light::getData()
{
    return Sensor::getData();
}


