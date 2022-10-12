/*
  Humidity.cpp
 
 Created on: 2022/10/1
 Author: Z1ppo

 */

#include "Humidity.h"
#include "Sensor.h"
#include <random>


float Humidity::aleaGenVal(){

	float FLOAT_MIN=0;
	float FLOAT_MAX=100;
	static std::random_device rd;
	static std::default_random_engine eg;
	static std::uniform_real_distribution<> distr(FLOAT_MIN, FLOAT_MAX);
	this->s_data=distr(eg);
	return this->s_data;
}
