/**
 * @author Cameron ROCHEBILLARD
 * @file Lumiere.cpp
 * @date 18/10/2022
 * @brief représente un capteur
 */

 //
 //Define guards 
 #ifndef LUMIERE_H
 #define LUMIERE_H

/**
 * @class Lumiere 
 * représente un capteur
 */

#include "Lumiere.hpp"
#include "Sensor.hpp"
#include <random>
#include <cstdlib> 

class Light : public Sensor<bool>
{
    public:
        bool L_min = false;
        bool L_max = true;

};


 #endif //LUMIERE_H