/**
 * @author Cameron ROCHEBILLARD
 * @file Pression.cpp
 * @date 18/10/2022
 * @brief représente un capteur
 */

 //
 //Define guards 
 #ifndef PRESSION_H
 #define PRESSION_H

/**
 * @class Pression 
 * représente un capteur
 */

#include "Pression.hpp"
#include "Sensor.hpp"
#include <random>
#include <cstdlib>

class Pression : public Sensor<int>
{
    public:
        int P_min = 55;
        int P_max = 850;

};


 #endif //PRESSION_H