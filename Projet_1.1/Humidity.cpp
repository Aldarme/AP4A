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

Humidity::Humidity():m_habs(0.0f){};                          //Constructeur par défaut

Humidity::Humidity(const float& h):m_habs(h){};               //Constructeur par recopie

Humidity& Humidity::operator=(const Humidity& param_l)        //Opérateur d'affectation
{
  this->m_habs = param_l.m_habs;
  return* this;
};

//function that collect habs from Humidity
Humidity Humidity::getData()
    {
  float _temp = Sensor::aleaGenVal();
  this->m_habs = _temp;
  return Humidity(_temp);
};

float Humidity::getValue()
{
  return this->m_habs;
};

std::string Humidity::getType()
{
  return "Humidity";
};
