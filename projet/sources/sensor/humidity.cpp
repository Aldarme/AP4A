//
// Created by rayan on 05/10/2022.
//
#include "humidity.h"

Humidity::Humidity() : Sensor(e_humidity, e_float){};

Humidity::~Humidity(){};

const SensorData& Humidity::getData()
{
    this->m_value = this->aleaGenVal<float>(10.1, 24.9);
    this->m_data.value = (this->m_value);

    return this->m_data;
}