/*
author: Tom PALLEAU
date: 10/1/2022
licence: free
class: Light
*/


#include "Light.hpp"

/**
 * @brief Construct a new Light:: Light object calling Sensor constructor with interval param
 * 
 */
Light::Light() : Sensor(0, 1){};

/**
 * @brief overide of getData to return bool instead of float
 * 
 * @return true 
 * @return false 
 */
bool Light::getData()
{   
    return rand() % 2;
}
