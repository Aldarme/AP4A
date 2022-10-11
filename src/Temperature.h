/*
 * @author raphael_perrin
 * @file Temperature.h
 * @date 05/10/2022
 * @brief Classe Temperature, classe dérivée de la superclasse Sensor. Sensor de la température présente dans l'avion
 */

#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include "Sensor.h"

template <class T>
class Temperature : public Sensor<T>
{
public :
	Temperature(){
		this->setData(this->aleaGenVal());
		this->setSpecifications("Temperature","degrees Celsius");
	}
	
protected :
	T aleaGenVal(){
		return static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/2)) + 23.;
	}
};

#endif // TEMPERATURE_H