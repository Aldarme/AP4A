/*
author: Tom PALLEAU
date: 10/1/2022
licence: free
class: Humidity
*/

#include "Humidity.hpp"

/**
 * @brief Construct a new Humidity:: Humidity object calling Sensor constructor with interval param
 * 
 */
Humidity::Humidity() : Sensor(20, 100){}
