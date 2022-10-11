/*
 * @author raphael_perrin
 * @file Light.h
 * @date 05/10/2022
 * @brief Classe Light, classe dérivée de la superclasse Sensor. Sensor de la lumière présente dans l'avion
 */

#ifndef LIGHT_H
#define LIGHT_H

#include "Sensor.h"

template <class T>
class Light : public Sensor<T>
{
public :
	Light(){
        this->setData(this->aleaGenVal());
	    this->setSpecifications("Light");
    }
protected :
	/*
    * @brief Methode permettant la génération d'un nombre aléatoire comprise entre 0 et 1 (ON ou OFF)
    * @return int
    * @param none
    */
	T aleaGenVal(){
        return rand() % 2 == 1 ? true : false;
    }
};

#endif // LIGHT_H