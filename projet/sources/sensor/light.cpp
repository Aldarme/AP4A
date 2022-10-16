//
// Created by rayan on 05/10/2022.
//

#include "light.h"

Light::Light() : Sensor<bool>(e_light, e_bool){};

Light::~Light(){};

const SensorData& Light::getData()
{
    this->m_value = this->aleaGenVal<int>() % 2;
    this->m_data.value = (this->m_value < 1) ? "eteint" : "allume";

    return this->m_data;
};