/**
 *@author Lola ROQUILLON 
 *@file Sensor.cpp
 *@date 28/09/2022
 *@brief Cette classe crée les valeurs des capteurs de manière aléatoire et les envoi au scheduler
 */

#include "Sensor.hpp"
#include <iostream>
#include <random>

Sensor::Sensor()
{   
}

Sensor::~Sensor()
{
}

int Sensor::getData(int min_p, int max_p)
{
    return (aleaGenVal(min_p, max_p)); 
}

int Sensor::aleaGenVal(int min_p, int max_p)
{
    //srand(time(NULL));
    return (rand()%max_p+min_p);  //création aléatoire
}