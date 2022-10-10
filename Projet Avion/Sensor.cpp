/**
 *  @author BIN ADNAN Muhammad Izzat Affandi
 *  @file Sensor.cpp
 *  @date 4/10/2022
 *  @brief This file contains implementations of the class "Sensor"
 */

#include "Sensor.hpp"
#include "stdlib.h"
#include <iostream>

int Sensor::getData()
{
    return this->m_data;
}
void Sensor::aleaGenVal(int lowest_p,int highest_p)
{
    this->m_data = rand() % ((highest_p-lowest_p+1) + lowest_p);
}

