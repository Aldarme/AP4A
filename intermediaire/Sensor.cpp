/**
 * @author Céliane ALLAIRE
 * @file Sensor.cpp
 * @date 28/09/2022
 * @brief 
 * */

#include "Sensor.hpp"
#include <iostream>
#include <cstdlib>

int Sensor::aleaGenVal(){
    this->m_data = this->getData();
    return this->m_data;
}

int Sensor::getData(){
    return (rand()%m_maxData)+m_minData;
}