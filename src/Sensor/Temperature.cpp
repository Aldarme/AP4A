/**
 * @file Temperature.cpp
 * @author Loric Ravassard
 * @brief hérite de Sensor et génère des valeurs de température
 * @version 1
 * @date 2022-09-28
 */

#include "Temperature.hpp"

Temperature::Temperature()
{
  this->m_min = 293;
  this->m_max = 299;
  this->m_unit = "K";
}

Temperature& Temperature::operator=(const Temperature& other_p)
{
  m_max = other_p.m_max;
  m_min = other_p.m_min;
  m_unit = other_p.m_unit;
  return *this;
}