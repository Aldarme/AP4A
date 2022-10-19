/**
 * @author Thibaud Leclere <thibaud.leclere@utbm.fr>
 * @file PressureSensor.cpp
 * @date 14/10/2022
 * @brief Implémentation de la class PressureSensor, héritée de Sensor
 */

#include "PressureSensor.hpp"

PressureSensor::PressureSensor() 
{
    m_minValue = 100;
    m_maxValue = 1015;
    m_name = "Pressure";
    m_unit = "hPa";
}
PressureSensor::~PressureSensor() = default;
PressureSensor::PressureSensor(const PressureSensor& ps) = default;
PressureSensor& PressureSensor::operator=(const PressureSensor& ps) = default;
