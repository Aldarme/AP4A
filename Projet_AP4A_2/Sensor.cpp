/**
 * @author choulot_hugo
 * @file Sensor.cpp
 * @date 20/09/2022
 * @brief Classe mère des différents capteurs
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include "Sensor.hpp"

using namespace std;

template <typename T>
//constructeur par défaut
Sensor<T>::Sensor()
{

    m_name = e_temperature;

}

template <typename T>
//constructeur par valeur
Sensor<T>::Sensor(const ESensors param_name)
{

    m_name = param_name;

}

template <typename T>
//constructeur par recopie
Sensor<T>::Sensor(const Sensor& s)
{

    this->m_name = s.m_name;
    this->m_valeur = s.m_valeur;

}

template <typename T>
//destructeur
Sensor<T>::~Sensor()
{

    cout << "Destructeur appelle\n" << endl;

}

template <typename T>
//operator
Sensor<T>& Sensor<T>::operator=(const Sensor<T>& s)
{

    this->m_name = s.m_name;
    this->m_valeur = s.m_valeur;

    return *this;

}

template <typename T>
/**
 * @brief permet de récupérer la valeur des capteurs
 * @return int
 * @param void
 */
T Sensor<T>::getData()
{

    return this->m_valeur;

}