
/**
 * @author Jules Ferlin
 * @file Pression.cpp
 * @date 03/10/2022
 * @brief Fichier source contenant l'implémentation des méthodes de la classe Pression
 */

#include "Pression.hpp"


Pression::Pression()
{
  // Initialise les attributs hérités de Sensor avec des valeurs cohérentes
  srand(time(nullptr));
  this->m_minValue = 76;
  this->m_maxValue = 81;
  this->m_name = "Pression";
  this->m_unite = "kPa";
}

Pression::Pression(const Pression &p_p) : Sensor<TYPE>(p_p) {} // Utilise le constructeur par recopie de Sensor

Pression::~Pression() = default;

Pression& Pression::operator=(const Pression &p_p)
{
  this->m_minValue = p_p.m_minValue;
  this->m_maxValue = p_p.m_maxValue;
  this->m_name = p_p.m_name;
  this->m_unite = p_p.m_unite;
  return *this;
}