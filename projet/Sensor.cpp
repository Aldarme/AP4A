/**
 * @author lois roger
 * @file Sensor.hpp
 * @date 05/10/2022
 * @brief les capteurs permettent de créer différentes données et de les récupérer
 */


#ifndef SENSOR_H
#define SENSOR_H
#include "Sensor.hpp"
#include <cstdlib>
#include <random>
#include <ctime>


int Sensor::aleaGenVal(int mini, int maxi)
{
    srand((unsigned int)time (0));
    int valaleatoire;
    valaleatoire = rand()%maxi +mini;
    return valaleatoire;
}

int Sensor::getData(int mini, int maxi)
{
    return aleaGenVal(mini, maxi);
}


#endif
