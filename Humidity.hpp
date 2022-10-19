/*
* @author Metral Greg
* @file Humidity.hpp
* @date 17/10/2022
* @brief capteur d'humidité, génère et stock des randoms float
*/

#ifndef HUMIDITY_H
#define HUMIDITY_H

#include <iostream>
#include <cstdio>
#include "Sensor.hpp"

class Humidity : public Sensor<float>
{
    protected :
        float aleaGenVal() 
        {
            return m_min + (static_cast<float>(rand()) * static_cast<float>(m_max - m_min) / RAND_MAX); // aleagenval pour float entre le min et max
        };


    public : 
        Humidity()
        {
            m_min = 0;
            m_max = 100;
            (*this).m_value = aleaGenVal();
        }

};

#endif