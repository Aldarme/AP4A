//
// Created by jules on 01/10/22.
//

#include "Light.hpp"


Light::Light()
{
    srand(time(nullptr));
    this->m_minValue = 0;
    this->m_maxValue = 1;
}
bool aleaGenVal()
{
    return rand()%2;
}

bool Light::getData()
{
    return this->aleaGenVal();
}