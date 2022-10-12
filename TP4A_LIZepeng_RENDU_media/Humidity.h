/*
Humidity.h
 
Created on: 2022/10/1日
      Author: Z1ppo LI
*/

#ifndef HUMIDITY_H
#define HUMIDITY_H

#include "Sensor.h"

class Humidity : public Sensor<float>{
public:

	float aleaGenVal();

};



#endif /* HUMIDITY_H*/