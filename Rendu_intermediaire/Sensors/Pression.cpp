
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
  this->m_minValeur = 76;
  this->m_maxValeur = 81;
  this->m_nomCapteur = "Pression";
  this->m_unite = "kPa";
}

Pression::Pression(const Pression &p_p) : Sensor<TYPE>(p_p) {} // Utilise le constructeur par recopiage de Sensor

Pression::~Pression() = default;

Pression& Pression::operator=(const Pression &p_p)
{
  this->m_minValeur = p_p.m_minValeur;
  this->m_maxValeur = p_p.m_maxValeur;
  this->m_nomCapteur = p_p.m_nomCapteur;
  this->m_unite = p_p.m_unite;
  return *this;
}