/**
 * @file Sensor.cpp
 * @author Loric Ravassard
 * @brief Génère aléatoirement des valeurs en fonction des min et max de ces derniers
 * @version 1
 * @date 2022-09-28
 */

#include "Sensor.hpp"
#include <cstdlib>
#include <time.h>

Sensor& Sensor::operator=(const Sensor& other_p)
{
  m_max = other_p.m_max;
  m_min = other_p.m_min;
  m_unit = other_p.m_unit;
  return *this;
}

int Sensor::aleaGenVal(int min_p, int max_p)
{
  srand(time(NULL));
  return rand()%(max_p-min_p + 1) + min_p;
}

int Sensor::getData()
{
  return this->aleaGenVal(this->m_min, this->m_max);
}

std::string Sensor::getUnit() const
{
  return this->m_unit;
}