/*
author: Tom PALLEAU
date: 10/1/2022
licence: free
class: Light
*/


#include "Light.hpp"
/**
 * @brief Construct a new Light:: Light object calling Sensor constructing with interval as param
 * 
 */
Light::Light() : Sensor(0, 1){}
