/*
Humidity.h
 
Created on: 2022/10/1日
      Author: Z1ppo LI
*/

#ifndef HUMIDITY_H_
#define HUMIDITY_H_

#include "Sensor.h"

class Humidity : public Sensor<float>{
public:

	float aleaGenVal();

};



#endif /* HUMIDITY_H_ */
