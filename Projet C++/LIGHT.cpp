/**
 * @author YUHUIFEI
 * @file LIGHT.cpp
 * @date 29/09/2022
 * @brief :La classe LIGHT permettra de caract¨¦riser un capteur de luminance.
 */
#ifndef LIGHT_CPP
#define LIGHT_CPP

#include "LIGHT.h"
#include<string>

void Light::sense()
{
    this->m_value = Sensor<bool>::aleaGenVal();
}

#endif