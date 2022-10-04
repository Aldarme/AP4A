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

Light::Light(const Light &l_p) : Sensor<bool>(l_p) {}

Light::~Light() = default;

Light& Light::operator=(const Light &l_p)
{
    this->m_minValue = l_p.m_minValue;
    this->m_maxValue = l_p.m_maxValue;
    this->m_name = l_p.m_name;
    this->m_unite = l_p.m_unite;
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