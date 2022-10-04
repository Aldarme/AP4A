/**
 * @author Thibaud Leclere <thibaud.leclere@utbm.fr>
 * @file Sensor.cpp
 * @date 28/09/2022
 * @brief Implémentation de la class Sensor et de ses classes héritées (Sensor spécifiques)
 * @brief Les Sensors permettent de générer et récupérer une valeur correspondant à leur type
 */

#include "Sensor.hpp"

Sensor::Sensor() = default;
Sensor::~Sensor() = default;
Sensor::Sensor(const Sensor& s) = default;
Sensor& Sensor::operator=(const Sensor& s) = default;


int Sensor::getData()
{
    return this->aleaGenVal();
}

int Sensor::aleaGenVal()
{
    return (std::rand() % (int)(std::floor(m_maxValue - m_minValue))) + (m_minValue);
}


HumiditySensor::HumiditySensor() 
{   // En %
    m_minValue = 0;
    m_maxValue = 101;
}

LightSensor::LightSensor()
{   // En bool
    m_minValue = 0;
    m_maxValue = 2;
}

PressureSensor::PressureSensor()
{   // En hPa
    m_minValue = 100;
    m_maxValue = 1015;
}

TemperatureSensor::TemperatureSensor()
{   //En K
    m_minValue = 280;
    m_maxValue = 306;
}
