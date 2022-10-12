//Sensor.cpp

#include <iostream>
#include <cstdlib>
#include "Humidity.hpp"
#include "Light.hpp"
#include "Temperature.hpp"
#include "Sound.hpp"
#include "Sensor.hpp"

Sensor::Sensor()
{
    this->m_value = 0;
    this->m_minValue = 0;
    this->m_maxValue = 1;
}

Sensor::Sensor(const Sensor &sensor)
{
    this->m_value = sensor.m_value;
    this->m_minValue = sensor.m_minValue;
    this->m_maxValue = sensor.m_maxValue;
}

Sensor::~Sensor() = default;

Sensor& Sensor::operator=(const Sensor& sensor)
{
    this->m_value = sensor.m_value;
    this->m_maxValue = sensor.m_maxValue;
    this->m_minValue = sensor.m_minValue;
    return *this;
}


void Sensor::setMinMax(int minVal_p, int maxVal_p)
{
    this->m_minValue = minVal_p;
    this->m_maxValue = maxVal_p;
}

void Sensor::aleaGenVal()
{
    this->m_value = (rand() % m_maxValue) + m_minValue;
}

int Sensor::getValue()
{
    return this->m_value;
}

