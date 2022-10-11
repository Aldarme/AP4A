/** 
 * @author SCHERRER Guillaume
 * @file Server.hpp
 * @date 25/09/2022
 * @brief definiton de la classe Light.hpp, classe représentant le capteur de lumière Lumens.
 * @brief classe dérivée de la classe Sensor 
*/

#ifndef LUM_H
#define LUM_H

// classe mère:
#include "Sensor.hpp"

class Light : public Sensor
{

private:
    float m_Light_min; // données en plus de la mère
    float m_Light_max; // ces données définissent aussi l'unité
    
public:

    Light(float, float);
    ~Light();
    Light(Light& light); // constructeur de recopie 
    Light& operator=(const Light& light); //opérateur d'affectation

    /**
     * @brief Cette fonction a pour but de "générer" les mesures du capteur en FLOAT en utilisant la méthode définie dans Sensor.cpp
     * @return la valeur mesurée est retourné
     * @param  /un min et un max
    */
    float aleaSensorVal();

    /**
    * @brief Cette fonciton a pour but de "récupérer" les mesures générées en FLOAT pour le rendu intermédiaire
    * @return le type de la valeur mesurée est retourné
    * @param //
   */
    float getData();
  

};

#endif