/**
 * @author Erhart Eliott
 * @file Sensor.hpp
 * @date 03/10/2022
 * @brief Définition de la classe Sensor
 */

//DEFINE GUARDS
#ifndef SENSOR_H
#define SENSOR_H

#include <cstdlib>
#include <ctime>
#include <math.h>

template <typename T>

/** 
 * @class Sensor
 * @brief Implémentation classe Sensor 
 */

class Sensor
{
public:
        T aleaVal;

        /// @brief Déclaration de la forme canonique de Coplien
        Sensor ():aleaVal(){}; // Constructeur par défaut
        Sensor (const Sensor& a):aleaVal(a.aleaVal){}; // Constructeur par recopie
        ~Sensor (){}; // Destructeur
        Sensor<T>& operator=(const Sensor<T>& sensor); 

        /**
         * @brief Génère une valeur aléatoire comprise entre le minimum et le maximum
         * @return this
         * @param min, max
         */
        virtual T aleaGenVal(T min, T max) = 0;
};

#endif // SENSOR_H