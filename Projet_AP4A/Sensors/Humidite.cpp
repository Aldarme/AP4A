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

Humidite::Humidite(const Humidite &h_p) : Sensor<float>(h_p) {}

Humidite::~Humidite() = default;

Humidite& Humidite::operator=(const Humidite &h_p)
{
    this->m_minValue = h_p.m_minValue;
    this->m_maxValue = h_p.m_maxValue;
    this->m_name = h_p.m_name;
    this->m_unite = h_p.m_unite;
    return *this;
}
