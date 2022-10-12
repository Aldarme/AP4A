/*
  Light.cpp
 
  Created on: 2022/10/1
   Author: Z1ppo
 */
#include "Light.h"
#include "time.h"
#include"Sensor.h"
#include "stdlib.h"

bool Light::aleaGenVal(){
	int a=0;
	int b=10;
	srand((unsigned)time(0));
	int val = (rand() % (b-a+1))+ a;
	if(val>5){
		this->s_data = true;
		return this->s_data;
	}
	else{
		this->s_data = false;
		return this->s_data;
	}
}