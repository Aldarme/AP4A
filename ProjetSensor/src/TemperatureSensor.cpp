/**
 * @author Thibaud Leclere <thibaud.leclere@utbm.fr>
 * @file TemperatureSensor.cpp
 * @date 14/10/2022
 * @brief Implémentation de la super-class spécifique TemperatureSensor, héritée de Sensor
 */

#include "TemperatureSensor.hpp"

TemperatureSensor::TemperatureSensor()
{
    m_minValue = 305;
    m_maxValue = 280;
    m_name = "Temperature";
    m_unit = "K";
}
TemperatureSensor::~TemperatureSensor() = default;
TemperatureSensor::TemperatureSensor(const TemperatureSensor& ts) = default;
TemperatureSensor& TemperatureSensor::operator=(const TemperatureSensor& ts) = default;
