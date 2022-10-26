/**
 * @file Pressure.cpp
 * @author Loric Ravassard
 * @brief hérite de Sensor et génère des valeurs de pression
 * @version 2
 * @date 2022-09-28
 */

#include "Pressure.hpp"
#include <cstdlib>
#include <time.h>

Pressure::Pressure()
{
  this->m_min = 75993;
  this->m_max = 82074;
  this->m_unit = "Pa";
  this->m_interval = 3;
  this->m_name = "Pressure";
}

Pressure::Pressure(const Pressure& other_p)
{
  m_min = other_p.m_min;
  m_max = other_p.m_max;
  m_unit = other_p.m_unit;
  m_interval = other_p.m_interval;
  m_name = other_p.m_name;
}

Pressure& Pressure::operator=(const Pressure& other_p)
{
  m_min = other_p.m_min;
  m_max = other_p.m_max;
  m_unit = other_p.m_unit;
  m_interval = other_p.m_interval;
  m_name = other_p.m_name;
  return *this;
}

int Pressure::aleaGenVal()
{
  srand(static_cast<unsigned int>(time(NULL))); //Perte possible de données mais comme c'est pour un random ce n'est pas un problème
  return rand()%(this->m_max-this->m_min + 1) + this->m_min;
}