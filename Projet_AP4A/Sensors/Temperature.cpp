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

Temperature::Temperature(const Temperature& param_temp) : Sensor<float>(param_temp) {}

Temperature::~Temperature() = default;

Temperature& Temperature::operator=(const Temperature& param_temp)
{
    this->m_minValue = param_temp.m_minValue;
    this->m_maxValue = param_temp.m_maxValue;
    this->m_name = param_temp.m_name;
    this->m_unite = param_temp.m_unite;
    return *this;
}