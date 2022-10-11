/**
* @author SZATKOWSKI Maxime
* @file Ligth.cpp
* @date 06/10/2022
* @brief Fichier source contenant les méthodes de la classe Light
*/

#include "Light.hpp"

//Constructeur par défaut
Light::Light()
{
    this->m_maxValue = 1200; //lumen
    this->m_minValue = 800;
}

//Constructeur par recopie
Light::Light(const Light& temp_p)
{
    this->m_maxValue = temp_p.m_maxValue;
    this->m_minValue = temp_p.m_minValue;
}

//Destructeur par défaut 
Light::~Light() 
{

}

//opérateur d'affectation
Light& Light::operator=(const Light & temp_p)
{
    this->m_minValue = temp_p.m_minValue;
    this->m_maxValue = temp_p.m_maxValue;
    return *this;
}