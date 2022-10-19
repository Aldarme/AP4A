/*
* @author Metral Greg
* @file Pression.hpp
* @date 17/10/2022
* @brief capteur de pression, génère et stock des randoms int
*/


#ifndef PRESSION_H
#define PRESSION_H

#include <iostream>
#include <cstdio>
#include "Sensor.hpp"

class Pression : public Sensor<int>
{
    protected :
        int aleaGenVal()  {
            return m_min+(rand()%(m_max-m_min+1)); //genere random int entre min et max
        };


    public : 
        Pression(){
            m_min = 700;
            m_max = 1400;
            (*this).m_value = aleaGenVal();
        };

};

#endif