/*
 * @author raphael_perrin
 * @file Light.h
 * @date 05/10/2022
 * @brief Classe Light, classe dérivée de la superclasse Sensor. Sensor de la lumière présente dans l'avion
 */

#ifndef LIGHT_H
#define LIGHT_H

#include "Sensor.h"

class Light : public Sensor
{
public :
	Light();
protected :
	/*
    * @brief Methode permettant la génération d'un nombre aléatoire comprise entre 0 et 1 (ON ou OFF)
    * @return int
    * @param none
    */
	int aleaGenVal();
};

#endif // LIGHT_H