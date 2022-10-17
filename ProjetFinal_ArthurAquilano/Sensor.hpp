/**
 * @author Arthur
 * @file Sensor.hpp
 * @date 03/10/22
 * @brief Déclaration de la classe Sensor
 */


//DEFINE_GUARDS
#ifndef SENSOR_H
#define SENSOR_H

#include <cstdlib>
#include <time.h>

/**
* @class Sensor
* @brief Déclaration de la classe Sensor
*/
template<typename T>
class Sensor
{
public:    
    T data;

    /** 
    * @brief Déclaration de la forme canonique de coplien
    * @return Rien
    * @param Ceux par défaut
    */
    Sensor<T>(): data(){};
    Sensor<T>(const Sensor<T>& s): data(s.data){};
    ~Sensor<T>(){};
    
    /** 
    * @brief Génère un entier aléatoire compris entre minValue et MaxValue
    * @return Int
    * @param Deux entiers minValue et maxValue
    */
    virtual T aleaGenVal(T min, T max);

};

#endif //SENSOR.H