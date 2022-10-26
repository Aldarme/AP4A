/**
 * @author mayer_thibault
 * @file Humidity.cpp
 * @date 02/10/2022
 * @brief capteur humidité qui hérite de Sensor
 */

#include <cstdlib>
#include <iostream>
#include "Sensor.hpp"
#include "Humidity.hpp"

//Constructeur par défaut
Humidity::Humidity(): Sensor(){};                          

//Constructeur par recopie
Humidity::Humidity(const Humidity& h): Sensor(h){};

//Constructeur par paramètre
Humidity::Humidity(time_t period_p): Sensor(period_p){};

//Opérateur d'affectation
Humidity& Humidity::operator=(const Humidity& param_l)        
{
  Sensor::operator=(param_l);
  return* this;
};

//function that collect habs from Humidity
Data<float> Humidity::getData()
{
  float temp = (rand() % 100)*0.9f;
  Data<float> newData(temp, getType());
  this->updateLastTime();
  return newData;
};

std::string Humidity::getType()
{
  return "Humidity";
};
