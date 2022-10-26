/*
  Light.cpp
 
  Created on: 2022/10/1
   Author: Z1ppo
 */
#include "Light.h"
#include"Sensor.h"
#include "stdlib.h"
#include "time.h"

bool Light::aleaGenVal(){
	int a=0;
	int b=10;
	srand((unsigned)time(0));
	int val = (rand() % (b-a+1))+ a;
	if(val>5){
		this->m_data = true;
		return this->m_data;
	}
	else{
		this->m_data = false;
		return this->m_data;
	}
}

