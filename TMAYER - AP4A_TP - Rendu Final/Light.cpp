/**
 * @author mayer_thibault
 * @file Light.cpp
 * @date 02/10/2022
 * @brief
 */

#include "Light.hpp"
#include "Sensor.hpp"
#include <cstdlib>
#include <iostream>

//Constructeur par défaut
Light::Light(): Sensor(){}                 	

//Constructeur par défaut
Light::Light(const Light& l): Sensor(l){};      	

//Constructeur par paramètre
Light::Light(time_t period_p): Sensor(period_p){};

//Opérateur d'affectation
Light& Light::operator=(const Light& param_l)   
{
  Sensor::operator=(param_l);
  return* this;
}

//function that collect lux from Light
Data<bool> Light::getData()
{
  bool temp;
  if(rand() %100 < 50)
  {
    temp = true;
  }
  else
  {
    temp = false;
  }
  Data<bool> newData(temp, getType());
  this->updateLastTime();
  return newData;
};

std::string Light::getType()
{ 
	return "Light";
};