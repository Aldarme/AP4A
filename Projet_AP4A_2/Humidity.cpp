#include "Humidity.hpp"

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

float Humidity::aleaGenVal(){
    int low = 0;
    int high = 100;
    return low + static_cast<float>(rand()) * static_cast<float>(high - low) / RAND_MAX;
}