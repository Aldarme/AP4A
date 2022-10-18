/**
 * @author Cameron ROCHEBILLARD
 * @file Humidite.cpp
 * @date 18/10/2022
 * @brief représente un capteur
 */

 //
 //Define guards 
 #ifndef HUMIDITE_H
 #define HUMIDITE_H


/**
 * @class Humidite
 * représente un capteur
 */

#include "Humidite.hpp"
#include "Sensor.hpp"
#include <random>
#include <cstdlib> 


class Humidity : public Sensor<float>
{
    public:
        float H_min = 40;
        float H_max = 60;

};

 #endif //HUMIDITE_H