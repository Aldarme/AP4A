/*
  Pressure.h
 
  Created on: 2022/10/2
    Author: Z1ppo
 */

#ifndef PRESSURE_H
#define PRESSURE_H
#include"Sensor.h"

class Pressure : public Sensor<int>{
public:
	int aleaGenVal();
};



#endif /* PRESSURE_H*/