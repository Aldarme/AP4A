/**
 * @file Light.cpp
 * @author Loric Ravassard
 * @brief hérite de Sensor et génère des valeurs de lumière
 * @version 1
 * @date 2022-09-28
 */

#include "Light.hpp"

Light::Light()
{
  this->m_min = 0;
  this->m_max = 1;
  this->m_unit = "bool";
}

Light& Light::operator=(const Light& other_p)
{
  m_max = other_p.m_max;
  m_min = other_p.m_min;
  m_unit = other_p.m_unit;
  return *this;
}