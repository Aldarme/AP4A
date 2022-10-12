/**
 * @file Pressure.cpp
 * @author Loric Ravassard
 * @brief hérite de Sensor et génère des valeurs de pression
 * @version 1
 * @date 2022-09-28
 */

#include "Pressure.hpp"

Pressure::Pressure()
{
  this->m_min = 75993;
  this->m_max = 82074;
  this->m_unit = "Pa";
}

Pressure& Pressure::operator=(const Pressure& other_p)
{
  m_max = other_p.m_max;
  m_min = other_p.m_min;
  m_unit = other_p.m_unit;
  return *this;
}