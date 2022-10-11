/**
 * @author Planchin Arnaud
 * @file Sensor.cpp
 * @date 03/10/2022
 * @brief Définition de chaque méthode de Sensor
 */

#include "Sensor.hpp"

Sensor Sensor::aleaGenVal(int min, int max)
{
    srand((int)time(0));
    data = rand()%(max-min + 1) + min;
    return *this;
}

int Sensor::GetData()
{
    return data;
}

Sensor Temperature::genAlea(){
    return aleaGenVal(10,25);
}

Sensor Humidity::genAlea(){
    return aleaGenVal(0,20);
}

Sensor Pression::genAlea(){
    return aleaGenVal(0,50);
}

Sensor Light::genAlea(){
    return aleaGenVal(0,1);
}