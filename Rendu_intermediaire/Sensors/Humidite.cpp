/**
 * @author Jules Ferlin
 * @file Humidite.cpp
 * @date 03/10/2022
 * @brief Fichier source contenant l'implémentation des méthodes de la classe Humidite
 */


#include "Humidite.hpp"

Humidite::Humidite()
{
  // Initialise les attributs hérités de Sensor avec des valeurs cohérentes
  srand(time(nullptr));
  this->m_minValeur = 40;
  this->m_maxValeur = 60;
  this->m_nomCapteur = "Humidite";
  this->m_unite = "%";
}


Humidite::Humidite(const Humidite &h_p) : Sensor<TYPE>(h_p) {} // Utilise le constructeur par recopiage de Sensor

Humidite::~Humidite() = default;

Humidite& Humidite::operator=(const Humidite &h_p)
{
  this->m_minValeur = h_p.m_minValeur;
  this->m_maxValeur = h_p.m_maxValeur;
  this->m_nomCapteur = h_p.m_nomCapteur;
  this->m_unite = h_p.m_unite;
  return *this;
}
