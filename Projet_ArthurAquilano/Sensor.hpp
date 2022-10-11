/**
 * @author Arthur
 * @file Sensor.hpp
 * @date 03/10/22
 * @brief Déclaration de la classe Sensor
 */


//DEFINE_GUARDS
#pragma once
#ifndef SENSOR_H
#define SENSOR_H

#include <cstdlib>
#include <time.h>

/**
* @class Sensor
* @brief Déclaration de la classe Sensor
*/
class Sensor
{
public:    
    int data;

    /** 
    * @brief Déclaration de la forme canonique de coplien
    * @return Rien
    * @param Ceux par défaut
    */
    Sensor(): data(){};
    Sensor(const Sensor& s): data(s.data){};
    ~Sensor(){};
    
    /** 
    * @brief Génère un entier aléatoire compris entre minValue et MaxValue
    * @return Int
    * @param Deux entiers minValue et maxValue
    */
    int aleaGenVal(int minValue, int maxValue);

};

#endif //SENSOR.H