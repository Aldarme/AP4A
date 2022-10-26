/*
  Temperature.cpp
 
  Created on: 2022/10/2日
   Author: Z1ppo
 */
#include "Sensor.h"
#include "Temperature.h"
#include <random>


float Temperature::aleaGenVal(){

	int FLOAT_MIN=-60;
	int FLOAT_MAX=60;
	std::random_device rd;
	std::default_random_engine eng(rd());
	std::uniform_real_distribution<float> distr(FLOAT_MIN, FLOAT_MAX);
	this->m_data=distr(eng);
	return this->m_data;
}


