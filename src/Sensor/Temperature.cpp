/**
 * @file Temperature.cpp
 * @author Loric Ravassard
 * @brief hérite de Sensor et génère des valeurs de température
 * @version 2
 * @date 2022-09-28
 */

#include "Temperature.hpp"
#include <cstdlib>
#include <time.h>
#include <random>

Temperature::Temperature()
{
  this->m_min = 293.0;
  this->m_max = 299.0;
  this->m_unit = "K";
  this->m_interval = 5;
  this->m_name = "Temperature";
}

Temperature::Temperature(const Temperature& other_p)
{
  m_min = other_p.m_min;
  m_max = other_p.m_max;
  m_unit = other_p.m_unit;
  m_interval = other_p.m_interval;
  m_name = other_p.m_name;
}

Temperature& Temperature::operator=(const Temperature& other_p)
{
  m_min = other_p.m_min;
  m_max = other_p.m_max;
  m_unit = other_p.m_unit;
  m_interval = other_p.m_interval;
  m_name = other_p.m_name;
  return *this;
}

float Temperature::aleaGenVal()
{
  std::random_device rd;
  std::default_random_engine eng(rd());
  std::uniform_real_distribution<float> distr(m_min, m_max);
  return distr(eng); 
}