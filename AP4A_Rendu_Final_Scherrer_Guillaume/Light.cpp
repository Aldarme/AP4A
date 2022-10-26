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

Light::Light() // constructor
{
    m_Light = false;
}

Light::~Light() {}    // destructor



bool Light::aleaSensorVal()    
{
    bool LightVal  =  Sensor::aleaGenValBool(); //utilise la méthode spéciale créée pour gérer la génération d'une valeur de type bool 

   return LightVal;  // 0 ou 1 si la lumière est allumée
}


bool Light::getData()
{
    return Sensor::getData();
}


