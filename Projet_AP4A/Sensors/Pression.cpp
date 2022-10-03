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

Pression::Pression(const Pression &param_p) : Sensor<int>(param_p) {}

Pression::~Pression() = default;

Pression& Pression::operator=(const Pression &param_p)
{
    this->m_minValue = param_p.m_minValue;
    this->m_maxValue = param_p.m_maxValue;
    this->m_name = param_p.m_name;
    this->m_unite = param_p.m_unite;
    return *this;
}

int Pression::aleaGenVal(int param_minVal, int param_maxVal)
{
    return std::rand() % (param_maxVal - param_minVal) + param_minVal;
}

int Pression::getData()
{
    return this->aleaGenVal(this->m_minValue, this->m_maxValue);
}