//
// Created by rayan on 05/10/2022.
//

#include "light.h"

Light::Light() : Sensor<float>(e_light, e_float){};

Light::~Light(){};

const SensorData& Light::getData()
{
    this->m_value = this->aleaGenVal<float>(0, 2);
    this->m_data.value = (this->m_value);

    return this->m_data;
};