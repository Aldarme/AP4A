/**
 * @author choulot_hugo
 * @file Sensor.cpp
 * @date 20/09/2022
 * @brief Classe mère des différents capteurs
 */

#include "Sensor.hpp"

using namespace std;

//déclaration template
template <typename T>

//constructeur par défaut
Sensor<T>::Sensor()
{

    m_name = e_temperature;

}

//déclaration template
template <typename T>

//constructeur par valeur
Sensor<T>::Sensor(const ESensors param_name)
{

    m_name = param_name;

}

//déclaration template
template <typename T>

//constructeur par recopie
Sensor<T>::Sensor(const Sensor& s)
{

    this->m_name = s.m_name;
    this->m_valeur = s.m_valeur;

}

//déclaration template
template <typename T>

//destructeur
Sensor<T>::~Sensor()
{

}

//déclaration template
template <typename T>

//operator
Sensor<T>& Sensor<T>::operator=(const Sensor<T>& s)
{

    this->m_name = s.m_name;
    this->m_valeur = s.m_valeur;

    return *this;

}