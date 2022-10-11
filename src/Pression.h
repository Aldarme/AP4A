/*
 * @author raphael_perrin
 * @file Pression.h
 * @date 05/10/2022
 * @brief Classe Pression, classe dérivée de la superclasse Sensor. Sensor de la pression actuelle dans l'avion
 */

#ifndef PRESSION_H
#define PRESSION_H
#include "Sensor.h"

template <class T>
class Pression : public Sensor<T>
{
public :
	Pression(){
        this->setData(this->aleaGenVal());
	    this->setSpecifications("Pression","hPa");
    }

protected :
	/*
    * @brief Methode permettant la génération d'un nombre aléatoire comprise entre 55 et 850 hPa
    * @return int
    * @param none
    */
	T aleaGenVal(){
        return rand() % 795 + 55;
    }
};

#endif // PRESSION_H