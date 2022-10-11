/** 
 * @author SCHERRER Guillaume
 * @file Umidity.hpp
 * @date 25/09/2022
 * @brief definiton de la classe Humidity.hpp, classe représentant le capteur d'humidité en % d'humidité relative.
 * @brief classe dérivée de la classe Sensor 
*/

#ifndef HUM_H
#define HUM_H

// classe mère:
#include "Sensor.hpp"

class Humidity : public Sensor
{

private:
    float m_Humidity_min; // données en plus de la mère
    float m_Humidity_max; // ces données définissent aussi l'unité
    
public:

    Humidity(float, float);
    ~Humidity();
    Humidity (Humidity& humidity); // constructeur de recopie 
    Humidity& operator=(const Humidity& humidity); //opérateur d'affectation

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