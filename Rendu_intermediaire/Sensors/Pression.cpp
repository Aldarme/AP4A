//
// Created by jules on 01/10/22.
//

#include "Pression.hpp"


Pression::Pression()
{
    srand(time(nullptr));
    this->m_minValue = 76;
    this->m_maxValue = 81;
    this->m_name = "Pression";
    this->m_unite = "kPa";
}

Pression::Pression(const Pression &p_p) : Sensor<TYPE>(p_p) {}

Pression::~Pression() = default;

Pression& Pression::operator=(const Pression &p_p)
{
    this->m_minValue = p_p.m_minValue;
    this->m_maxValue = p_p.m_maxValue;
    this->m_name = p_p.m_name;
    this->m_unite = p_p.m_unite;
    return *this;
}