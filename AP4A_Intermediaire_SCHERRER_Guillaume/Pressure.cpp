/** 
 * @author SCHERRER Guillaume
 * @file Server.cpp
 * @date 25/09/2022
 * @brief definiton ds corps des méthodes de Pressure.hpp
 *  
*/

// génériques:
#include <iostream>
#include <stdlib.h>     /* srand, rand */

// classe:
#include "Sensor.hpp"
#include "Pressure.hpp"

Pressure::Pressure(float min, float max) // constructor
{
    m_Pressure_min = min;
    m_Pressure_max = max;
}

Pressure::~Pressure() {}    // destructor



float Pressure::aleaSensorVal()    //
{
    float PressureVal  =  Sensor::aleaGenVal(m_Pressure_min, m_Pressure_max); // writes to m_data

   return PressureVal; // 
}


float Pressure::getData()
{
    return Sensor::getData();
}


