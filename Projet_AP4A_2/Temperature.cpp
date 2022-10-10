#include "Temperature.hpp"

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

float Temperature::aleaGenVal(){
    int low = 30;
    int high = 45;
    return low + static_cast<float>(rand()) * static_cast<float>(high - low) / RAND_MAX;
}