//
// Created by rayan on 26/09/2022.
//

#include "Temperature.h"
#include "ctime"


Temperature::Temperature() : Sensor<float>(temperature, e_float){};


Temperature::~Temperature() {
}

const SensorData& Temperature::getData()
{
    this->m_value = this->aleaGenVal(10, 3);
    this->m_data.value = std::to_string(this->m_value);

    return this->m_data;
}