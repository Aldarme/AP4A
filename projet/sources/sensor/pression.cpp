//
// Created by rayan on 05/10/2022.
//
#include "pression.h"
Pression::Pression() : Sensor<float>(e_pressure, e_float){};

Pression::~Pression(){};

const SensorData& Pression::getData()
{
    this->m_value = this->aleaGenVal<float>(62000, 76000);
    this->m_data.value = (this->m_value);

    return this->m_data;
};