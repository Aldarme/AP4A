/*
 * @author raphael_perrin
 * @file Temperature.h
 * @date 05/10/2022
 * @brief Classe Temperature, classe dérivée de la superclasse Sensor. Sensor de la température présente dans l'avion
 */

#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include "Sensor.h"

class Temperature : public Sensor
{
public :
	Temperature();
	
protected :
	int aleaGenVal() override;
};

#endif // TEMPERATURE_H