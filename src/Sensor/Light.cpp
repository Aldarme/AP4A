/**
 * @file Light.cpp
 * @author Loric Ravassard
 * @brief hérite de Sensor et génère des valeurs de lumière
 * @version 2
 * @date 2022-09-28
 */

#include "Light.hpp"
#include <cstdlib>
#include <time.h>

Light::Light()
{
  this->m_min = false;
  this->m_max = true;
  this->m_unit = "bool";
  this->m_interval = 1;
  this->m_name = "Light";
}

Light::Light(const Light& other_p)
{
  m_min = other_p.m_min;
  m_max = other_p.m_max;
  m_unit = other_p.m_unit;
  m_interval = other_p.m_interval;
  m_name = other_p.m_name;
}

Light& Light::operator=(const Light& other_p)
{
  m_max = other_p.m_max;
  m_min = other_p.m_min;
  m_unit = other_p.m_unit;
  m_interval = other_p.m_interval;
  m_name = other_p.m_name;
  return *this;
}

bool Light::aleaGenVal()
{
  srand(static_cast<unsigned int>(time(NULL))); //Perte possible de données mais comme c'est pour un random ce n'est pas un problème
  return rand()%2;
}