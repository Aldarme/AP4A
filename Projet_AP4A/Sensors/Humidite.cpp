//
// Created by jules on 01/10/22.
//

#include "Humidite.hpp"

Humidite::Humidite()
{
    srand(time(nullptr));
    this->m_minValue = 40;
    this->m_maxValue = 60;
    this->m_name = "Humidite";
    this->m_unite = "%";
}

Humidite::Humidite(const Humidite &param_h) : Sensor<float>(param_h) {}

Humidite::~Humidite() = default;

Humidite& Humidite::operator=(const Humidite &param_h)
{
    this->m_minValue = param_h.m_minValue;
    this->m_maxValue = param_h.m_maxValue;
    this->m_name = param_h.m_name;
    this->m_unite = param_h.m_unite;
    return *this;
}
