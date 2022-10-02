//
// Created by rayan on 28/09/2022.
//

#include "Pression.h"
#include <ctime>

Pression::Pression() : Sensor<int>(pressure, e_int){};


Pression::~Pression() {

}

const SensorData& Pression::getData()
{
    this->m_value = this->aleaGenVal<int>(1, 1);
    this->m_data.value = std::to_string(this->m_value);

    return this->m_data;
};

