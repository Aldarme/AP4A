/**
 *  @author BIN ADNAN Muhammad Izzat Affandi
 *  @file Sensor.cpp
 *  @date 4/10/2022
 *  @brief This file contains implementations of the class "Sensor"
 */

#include "Sensor.hpp"
#include "stdlib.h"
#include <iostream>

template <class T> T Sensor<T>::getData()
{
    this->m_data = this->aleaGenVal();
    return this->m_data;
}

template <class T> T Sensor<T>::aleaGenVal()
{
    return rand() % ((25-20+1) + 20);
}

float Temperature::aleaGenVal()
{
    return rand() % 7 + 20;
}

int Pression::aleaGenVal()
{
    return rand() % 2 + 11;
}

float Humidity::aleaGenVal()
{
    return rand() % 21 + 1;
}

bool Light::aleaGenVal()
{
    if(rand() % 2 + 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}