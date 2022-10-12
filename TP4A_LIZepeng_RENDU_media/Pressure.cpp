/*
  Pressure.cpp
 
   Created on: 2022/10/2
   Author: Z1ppo
 */
#include "Pressure.h"
#include "Sensor.h"
#include "stdlib.h"
#include "time.h"

int Pressure::aleaGenVal(){
	int a = 0;
	int b = 101;
	srand((unsigned)time(0));
	this->s_data = (rand() % (b-a+1))+ a;

	return this->s_data;
}