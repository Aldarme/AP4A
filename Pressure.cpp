/*
author: Tom PALLEAU
date: 10/1/2022
licence: free
class: Prssure
*/

#include "Pressure.hpp"

/**
 * @brief Construct a new Pressure:: Pressure object using Sensor constructor with interval as param
 * 
 */
Pressure::Pressure() : Sensor(0, 20){}

/**
 * @brief overide of getData to return int instead of float
 * 
 * @return int
 */
int Pressure::getData()
{
    return (rand() % (m_MAX_VAL - m_MIN_VAL)) + m_MIN_VAL;
}