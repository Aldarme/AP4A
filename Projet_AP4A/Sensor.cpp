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

#include "Scheduler.hpp"
#include "Sensor.hpp"
#include "Server.hpp"

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
 * @brief permet de générer des valeurs aléatoires de int pour les différents capteurs
 * @return int
 * @param void
 */
T Sensor<T>::aleaGenVal()
{

    T m_valeur;

    switch (this->m_name){

        case e_temperature :
        {

            int low = 30;
            int high = 45;
            m_valeur = low + static_cast<float>(rand()) * static_cast<float>(high - low) / RAND_MAX;

        }
        break;

        case e_humidity :
        {
            
            int low = 0;
            int high = 100;
            m_valeur = low + static_cast<float>(rand()) * static_cast<float>(high - low) / RAND_MAX;

        }
        break;

        case e_light :
        {

            m_valeur = rand() > (RAND_MAX / 2);;

        }
        break;
        
        case e_pression :
        {

            m_valeur = rand() % 100 + 700;

        }
        break;

        default :
        {

            return m_valeur = 0;
            cout << "valeur aléatoire non initialisée" << endl;

        }
        break;
    }

    return m_valeur;
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

//constructeur par défaut des capteurs Température
Temperature::Temperature()
{

    this->m_name = ESensors::e_temperature;
    this->m_valeur = 0;

}

//constructeur par recopie des capteurs Température
Temperature::Temperature(const Temperature& t)
{

    this->m_name = t.m_name;
    this->m_valeur = t.m_valeur;

}

//destructeur
Temperature::~Temperature()
{

}

//constructeur par défaut des capteurs Humidity
Humidity::Humidity()
{

    this->m_name = ESensors::e_humidity;
    this->m_valeur = 0;

}

//constructeur par recopie des capteurs Humidity
Humidity::Humidity(const Humidity& h)
{

    this->m_name = h.m_name;
    this->m_valeur = h.m_valeur;

}

//destructeur
Humidity::~Humidity()
{

}

//constructeur par défaut des capteurs Light
Light::Light()
{

    this->m_name = ESensors::e_light;
    this->m_valeur = 0;

}

//constructeur par recopie des capteurs Light
Light::Light(const Light& l)
{

    this->m_name = l.m_name;
    this->m_valeur = l.m_valeur;

}

//destructeur
Light::~Light()
{

}


//constructeur par défaut des capteurs Pression
Pression::Pression()
{

    this->m_name = ESensors::e_pression;
    this->m_valeur = 0;

}

//constructeur par recopie des capteurs Pression
Pression::Pression(const Pression& p)
{

    this->m_name = p.m_name;
    this->m_valeur = p.m_valeur;

}

//destructeur
Pression::~Pression()
{
    
}