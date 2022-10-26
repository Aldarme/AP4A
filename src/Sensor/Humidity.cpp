/**
 * @file Humidity.cpp
 * @author Loric Ravassard
 * @brief hérite de Sensor et génère des valeurs d'humidité
 * @version 2
 * @date 2022-09-28
 */

#include "Humidity.hpp"
#include <cstdlib>
#include <time.h>
#include <random>

Humidity::Humidity()
{
  this->m_min = 12.0;
  this->m_max = 28.0;
  this->m_unit = "%";
  this->m_interval = 8;
  this->m_name = "Humidity";
}

Humidity::Humidity(const Humidity& other_p)
{
  m_min = other_p.m_min;
  m_max = other_p.m_max;
  m_unit = other_p.m_unit;
  m_interval = other_p.m_interval;
  m_name = other_p.m_name;
}

Humidity& Humidity::operator=(const Humidity& other_p)
{
  m_max = other_p.m_max;
  m_min = other_p.m_min;
  m_unit = other_p.m_unit;
  m_interval = other_p.m_interval;
  m_name = other_p.m_name;
  return *this;
}

float Humidity::aleaGenVal()
{
  std::random_device rd;
  std::default_random_engine eng(rd());
  std::uniform_real_distribution<float> distr(m_min, m_max);
  return distr(eng); 
}