/*
 * @author raphael_perrin
 * @file Pression.h
 * @date 05/10/2022
 * @brief Classe Pression, classe dérivée de la superclasse Sensor. Sensor de la pression actuelle dans l'avion
 */

#ifndef PRESSION_H
#define PRESSION_H
#include "Sensor.h"

class Pression : public Sensor
{
public :
	Pression();

protected :
	/*
    * @brief Methode permettant la génération d'un nombre aléatoire comprise entre 55 et 850 hPa
    * @return int
    * @param none
    */
	int aleaGenVal();
};

#endif // PRESSION_H