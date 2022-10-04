//
// Created by jules on 01/10/22.
//

#include "Temperature.hpp"

Temperature::Temperature()
{
    srand(time(nullptr));
    this->m_maxValue = 30;
    this->m_minValue = 20;
    this->m_name = "Temperature";
    this->m_unite = "\370C";
}

Temperature::Temperature(const Temperature& temp_p) : Sensor<float>(temp_p) {}

Temperature::~Temperature() = default;

Temperature& Temperature::operator=(const Temperature& temp_p)
{
    this->m_minValue = temp_p.m_minValue;
    this->m_maxValue = temp_p.m_maxValue;
    this->m_name = temp_p.m_name;
    this->m_unite = temp_p.m_unite;
    return *this;
}