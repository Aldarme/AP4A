/** 
 * @author SCHERRER Guillaume
 * @file Sensor.cpp
 * @date 25/09/2022
 * @brief definiton ds corps des méthodes de Sensor.hpp.
 *  
*/

// génériques:
#include <iostream>
#include <stdlib.h>     /* srand, rand */

// classe:
#include "Sensor.hpp"

Sensor::Sensor() { m_data=0.0; }     // default constructor
Sensor::Sensor(Sensor& sensor) { m_data = 0.0; }       // constructeur de recopie 
Sensor::~Sensor() {}    // destructor


float Sensor::aleaGenVal(float min, float max)
{
    float generated_value;
    generated_value = (float)rand() / (float)RAND_MAX ;  // valeur entre 0.0 et 1.0
    m_data =  (max - min) * generated_value + min; // m_data entre min et max
  
    return m_data; // return generated sensor value
}


float Sensor::getData()
{
    return m_data; 
}

 