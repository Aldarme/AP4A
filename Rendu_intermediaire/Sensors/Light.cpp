/**
 * @author Jules Ferlin
 * @file Light.cpp
 * @date 03/10/2022
 * @brief Fichier source contenant l'implémentation des méthodes de la classe Light
 */


#include "Light.hpp"


Light::Light()
{
    srand(time(nullptr));
    this->m_minValue = false;
    this->m_maxValue = true;
    this->m_name = "Light";
    this->m_unite = "";
}

Light::Light(const Light &l_p) : Sensor<TYPE>(l_p) {}

Light::~Light() = default;

Light& Light::operator=(const Light &l_p)
{
    this->m_minValue = l_p.m_minValue;
    this->m_maxValue = l_p.m_maxValue;
    this->m_name = l_p.m_name;
    this->m_unite = l_p.m_unite;
    return *this;
}

TYPE Light::aleaGenVal()
{
    return (rand()) % 2;
}

TYPE Light::getData()
{
    return this->aleaGenVal();
}