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
}

bool Light::aleaGenVal()
{
    return (rand()) % 2;
}

bool Light::getData()
{
    return this->aleaGenVal();
}