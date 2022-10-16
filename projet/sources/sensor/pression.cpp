//
// Created by rayan on 05/10/2022.
//
#include "pression.h"
Pression::Pression() : Sensor<int>(e_pressure, e_int){};

Pression::~Pression(){};

const SensorData& Pression::getData()
{
    this->m_value = this->aleaGenVal<int>(62000, 76000);
    this->m_data.value = std::to_string(this->m_value);

    return this->m_data;
};