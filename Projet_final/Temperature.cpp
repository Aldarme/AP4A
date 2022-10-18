/**
 * @author Cameron ROCHEBILLARD
 * @file temperature.cpp
 * @date 18/10/2022
 * @brief représente un capteur
 */

 //
 //Define guards 
 #ifndef TEMPERATURE_H
 #define TEMPERATURE_H


/**
 * @class Temperature
 * représente un capteur
 */

#include "Sensor.hpp"
#include "Temperature.hpp"
#include <random>
#include <cstdlib> 



class Temperature : public Sensor<float>
{
    public:
        float T_min = 23;
        float T_max = 25;

};

 #endif //TEMPERATURE_H