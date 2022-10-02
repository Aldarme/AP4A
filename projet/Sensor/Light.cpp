//
// Created by rayan on 28/09/2022.
//

#include "Light.h"
#include <ctime>

Light::Light() : Sensor<bool>(light, e_bool){};


Light::~Light() {

}

const SensorData& Light::getData()
{
    this->m_value = this->aleaGenVal<int>() % 2;
    this->m_data.value = (this->m_value < 1) ? "false" : "true";

    return this->m_data;
};
