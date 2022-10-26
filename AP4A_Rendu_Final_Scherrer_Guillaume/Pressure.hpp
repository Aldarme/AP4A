/** 
 * @author SCHERRER Guillaume
 * @file Server.hpp
 * @date 25/09/2022
 * @brief definiton de la classe Pressure.hpp, classe représentant le capteur de pression en Pascal (Pa).
 * @brief classe dérivée de la classe Sensor 
*/

#ifndef PRESS_H
#define PRESS_H

// classe mère:
#include "Sensor.hpp"

class Pressure : public Sensor<int>  
{

private:
    int m_Pressure_min; // données en plus de la mère
    int m_Pressure_max; // ces données définissent aussi l'unité
    
public:

    Pressure(float, float);
    ~Pressure();
    Pressure(Pressure& pressure); // constructeur de recopie 
    Pressure& operator=(const Pressure& pressure); //opérateur d'affectation

    /**
     * @brief Cette fonction a pour but de "générer" les mesures du capteur en utilisant la méthode définie dans Sensor.cpp
     * @return la valeur mesurée est retourné
     * @param  /un min et un max
    */
    int aleaSensorVal();

    /**
    * @brief Cette fonciton a pour but de "récupérer" les mesures générées en FLOAT pour le rendu intermédiaire
    * @return le type de la valeur mesurée est retourné
    * @param //
   */
    int getData();
  

};

#endif