/**
 * @author Jules Ferlin
 * @file Light.cpp
 * @date 03/10/2022
 * @brief Fichier source contenant l'implémentation des méthodes de la classe Light
 */


#include "Light.hpp"


Light::Light()
{
  // Initialise les attributs hérités de Sensor avec des valeurs cohérentes
  srand(time(nullptr));
  this->m_minValeur = false;
  this->m_maxValeur = true;
  this->m_nomCapteur = "Light";
  this->m_unite = "";
}

Light::Light(const Light &l_p) : Sensor<bool>(l_p) {} // Utilise le constructeur par recopiage de Sensor

Light::~Light() = default;

Light& Light::operator=(const Light &l_p)
{
  this->m_minValeur = l_p.m_minValeur;
  this->m_maxValeur = l_p.m_maxValeur;
  this->m_nomCapteur = l_p.m_nomCapteur;
  this->m_unite = l_p.m_unite;
  return *this;
}

bool Light::aleaGenVal()
{
  // retourne 1 ou 0 pour correspondre au capteur
  return (rand()) % 2;
}

bool Light::getData()
{
  return this->aleaGenVal();
}