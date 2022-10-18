/**
 * @author Cameron ROCHEBILLARD
 * @file Sensor.cpp
 * @date 4/10/2022
 * @brief permet de réunir et envoyer les données des capteurs
 */

 //
 //Define guards 
 #ifndef SENSOR_H
 #define SENSOR_H

#include "Sensor.hpp"
#include <random>
#include <cstdlib> 


/**
 * @class Sensor
 * récupère et renvoie les données des capteur
 */

template <class S> class Sensor
{
    public:
        S getData(S max, S min)
        {
            return aleaGenVal(max, min);
        }
        S aleaGenVal(S max, S min)
        {
            srand((unsigned)time(0)); 
            S i;
            S m = max - min;
            i = (rand()%m)+min;
            return i; 
        }
};








 #endif //SENSOR_H