//
// Created by rayan on 28/09/2022.
//

#include "Humidity.h"
#include <ctime>
#include "../Enum.h"

Humidity::Humidity() : Sensor(humidity, e_float){};


Humidity::~Humidity() {
}

const SensorData& Humidity::getData()
{
    this->m_value = this->aleaGenVal(10, 60);
    this->m_data.value = std::to_string(this->m_value);

    return this->m_data;
}