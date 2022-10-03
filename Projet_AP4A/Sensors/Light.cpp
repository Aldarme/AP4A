//
// Created by jules on 01/10/22.
//

#include "Light.hpp"


Light::Light()
{
    srand(time(nullptr));
    this->m_minValue = false;
    this->m_maxValue = true;
    this->m_name = "Light";
    this->m_unite = "";
}

Light::Light(const Light &param_l) : Sensor<bool>(param_l) {}

Light::~Light() = default;

Light& Light::operator=(const Light &param_l)
{
    this->m_minValue = param_l.m_minValue;
    this->m_maxValue = param_l.m_maxValue;
    this->m_name = param_l.m_name;
    this->m_unite = param_l.m_unite;
    return *this;
}

bool Light::aleaGenVal()
{
    return (rand()) % 2;
}

bool Light::getData()
{
    return this->aleaGenVal();
}