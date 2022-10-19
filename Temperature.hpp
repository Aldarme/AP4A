/*
* @author Metral Greg
* @file Temperature.hpp
* @date 17/10/2022
* @brief capteur de temperature, génère et stock des randoms float
*/

#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <iostream>
#include <cstdio>
#include "Sensor.hpp"


class Temperature : public Sensor<float>
{
    protected :
        float aleaGenVal() 
        {
            return m_min + (static_cast<float>(rand()) * static_cast<float>(m_max - m_min) / RAND_MAX);
        };

    
    public : 
        Temperature()
        {
            m_min = 0;
            m_max = 50;
            (*this).m_value = aleaGenVal();
        };
};

#endif