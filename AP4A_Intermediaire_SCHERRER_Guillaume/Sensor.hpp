/** 
 * @author SCHERRER Guillaume
 * @file Sensor.hpp
 * @date 25/09/2022
 * @brief Cette classe a pour but de contenir toutes les méthodes nécéssaires pour que 
 * les capteurs héritant de cette classe puissent faire leur mesures.
 *  
*/

#ifndef SENSOR_H
#define SENSOR_H

#include <iostream>


class Sensor
{
public: 

    Sensor();   // constructeur par défaut
    ~Sensor();  // destructeur
    Sensor (Sensor& sensor); // constructeur de recopie
    Sensor& operator=(const Sensor& sensor); //opérateur d'affectation


    /** 
     * @brief Cette fonciton a pour but de "récupérer" les mesures générées en FLOAT pour le rendu intermédiaire
     * @return le type de la valeur mesurée est retourné 
     * @param //
    */
    float getData();

    /** 
     * @brief Cette fonciton a pour but de "générer" les mesures du capteur en FLOAT pour le rendu intermédiaire
     * @return le type de la valeur mesurée est retourné // ? pas sur? utilité de get val alors???
     * @param //
    */
    float aleaGenVal(float, float);

private:

    float m_data; // mesure fournie par le capteur ( valeur aléatoire générée par aleaGenval() )

};

#endif
