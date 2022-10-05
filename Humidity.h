/*
 * @author raphael_perrin
 * @file Humidity.h
 * @date 05/10/2022
 * @brief Classe Humidity, classe dérivée de la superclasse Sensor. Sensor d'humidité présente dans l'avion
 */

#ifndef HUMIDITY_H
#define HUMIDITY_H

#include "Sensor.h"

class Humidity : public Sensor
{
public:
    Humidity();
protected :
    /*
    * @brief Methode permettant la génération d'un nombre aléatoire comprise entre 0 et 100%
    * @return int
    * @param none
    */
	int aleaGenVal();
};

#endif // HUMIDITY_H