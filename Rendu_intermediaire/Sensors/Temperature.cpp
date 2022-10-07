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
  this->m_maxValeur = 30;
  this->m_minValeur = 20;
  this->m_nomCapteur = "Temperature";
  this->m_unite = "\370C";
}

Temperature::Temperature(const Temperature& temp_p) : Sensor<TYPE>(temp_p) {} // Utilise le constructeur par recopiage de Sensor

Temperature::~Temperature() = default;

Temperature& Temperature::operator=(const Temperature& temp_p)
{
  this->m_minValeur = temp_p.m_minValeur;
  this->m_maxValeur = temp_p.m_maxValeur;
  this->m_nomCapteur = temp_p.m_nomCapteur;
  this->m_unite = temp_p.m_unite;
  return *this;
}