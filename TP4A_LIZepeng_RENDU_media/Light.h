/*
  Light.h
 
  Created on: 2022/10/1
  Author: Z1ppo
*/

#ifndef LIGHT_H
#define LIGHT_H
#include "Sensor.h"

class Light : public Sensor<bool>{
public:

	bool aleaGenVal();
};




#endif /* LIGHT_H */