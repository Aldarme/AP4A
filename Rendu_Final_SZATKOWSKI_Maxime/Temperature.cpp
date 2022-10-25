/**
* @author SZATKOWSKI Maxime
* @file Temperature.hpp
* @date 06/10/2022
* @brief Permet de g�n�rere des objets de type capteurs de temp�rature
*/

#include "Temperature.hpp"


//Constructeur par d�faut
Temperature::Temperature()
{
    this->m_maxValue = 30.0;     //Valeur maximale du capteur de temp�rature en degr�s celsius
    this->m_minValue = 18.0;    // Valeur minimale du capteur de temp�rature en degr�s celsius
}

//Constructeur par recopie
Temperature::Temperature(const Temperature& temp_p)
{
    this->m_maxValue = temp_p.m_maxValue;
    this->m_minValue = temp_p.m_minValue;
}

//Destructeur par d�faut
Temperature::~Temperature() = default;

//Op�rateur d'affectation
Temperature& Temperature::operator=(const Temperature & temp_p)
{
    this->m_minValue = temp_p.m_minValue;
    this->m_maxValue = temp_p.m_maxValue;
    return *this;
}