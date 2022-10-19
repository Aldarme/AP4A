/**
 * @author Thibaud Leclere <thibaud.leclere@utbm.fr>
 * @file LightSensor.cpp
 * @date 14/10/2022
 * @brief Implémentation de la class LightSensor, héritée de Sensor
 */

#include "LightSensor.hpp"

LightSensor::LightSensor() 
{
    m_minValue = 0;
    m_maxValue = 2;
    m_name = "Lighting";
    m_unit = "";
}
LightSensor::~LightSensor() = default;
LightSensor::LightSensor(const LightSensor& ls) = default;
LightSensor& LightSensor::operator=(const LightSensor& ls) = default;
