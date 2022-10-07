/**
 * @author Jules Ferlin
 * @file Temperature.cpp
 * @date 03/10/2022
 * @brief Fichier source contenant l'implémentation des méthodes de la classe Température
 */


#include "Temperature.hpp"

Temperature::Temperature()
{
  // Initialise les attributs hérités de Sensor avec des valeurs cohérentes
  srand(time(nullptr));
  this->m_maxValue = 30;
  this->m_minValue = 20;
  this->m_name = "Temperature";
  this->m_unite = "\370C";
}

Temperature::Temperature(const Temperature& temp_p) : Sensor<TYPE>(temp_p) {} // Utilise le constructeur par re-copie de Sensor

Temperature::~Temperature() = default;

Temperature& Temperature::operator=(const Temperature& temp_p)
{
  this->m_minValue = temp_p.m_minValue;
  this->m_maxValue = temp_p.m_maxValue;
  this->m_name = temp_p.m_name;
  this->m_unite = temp_p.m_unite;
  return *this;
}