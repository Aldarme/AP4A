//
// Created by rayan on 05/10/2022.
//
#include "temperature.h"

Temperature::Temperature() : Sensor<float>(e_temperature, e_float){};

Temperature::~Temperature(){};

const SensorData& Temperature::getData()
{
    this->m_value = this->aleaGenVal<float>(22.1, 25.9);
    this->m_data.value = std::to_string(this->m_value);

    return this->m_data;
}