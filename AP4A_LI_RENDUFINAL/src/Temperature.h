/*
  Temperature.h
 
  Created on: 2022/10/2日
  Author: Z1ppo
 */

#ifndef TEMPERATURE_H_
#define TEMPERATURE_H_
#include "Sensor.h"



class Temperature : public Sensor<float>{
public:
	float aleaGenVal();
};




#endif /* TEMPERATURE_H_ */
