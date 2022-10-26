/** 
 * @author SCHERRER Guillaume
 * @file Temperature.hpp
 * @date 25/09/2022
 * @brief definiton de la classe Temperature.hpp, classe représentant le capteur de température.
 * @brief classe dérivée de la classe Sensor 
*/

#ifndef TEMP_H
#define TEMP_H

// classe mère:
#include "Sensor.hpp"

class Temperature : public Sensor<float>
{

private:
    float m_temperature_min; // données en plus de la mère
    float m_temperature_max; // ces données définissent aussi l'unité
    
public:

    Temperature(float, float);
    ~Temperature();
    Temperature(Temperature& temperature); // constructeur de recopie
    Temperature& operator=(const Temperature& temperature); //opérateur d'affectation 



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