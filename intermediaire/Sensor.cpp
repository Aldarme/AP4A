/**
 * @author Céliane ALLAIRE
 * @file Sensor.cpp
 * @date 28/09/2022
 * @brief 
 * */

#include "Sensor.hpp"
#include <iostream>
#include <cstdlib>

float Sensor::aleaGenVal(){

}

float Sensor::getData(){
    return (rand()%m_maxData)+m_minData
}