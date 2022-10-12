/**
 * @file Humidity.cpp
 * @author Loric Ravassard
 * @brief hérite de Sensor et génère des valeurs d'humidité
 * @version 1
 * @date 2022-09-28
 */

#include "Humidity.hpp"

Humidity::Humidity()
{
  this->m_min = 12;
  this->m_max = 28;
  this->m_unit = "%";
}

Humidity& Humidity::operator=(const Humidity& other_p)
{
  m_max = other_p.m_max;
  m_min = other_p.m_min;
  m_unit = other_p.m_unit;
  return *this;
}