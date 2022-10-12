/*
  Temperature.h
 
  Created on: 2022/10/2日
  Author: Z1ppo
 */

#ifndef TEMPERATURE_H
#define TEMPERATURE_H
#include "Sensor.h"



class Temperature : public Sensor<float>{
public:
	float aleaGenVal();
};




#endif /* TEMPERATURE_H*/