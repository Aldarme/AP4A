/**
 * @author Thibaud Leclere <thibaud.leclere@utbm.fr>
 * @file HumiditySensor.cpp
 * @date 14/10/2022
 * @brief Implémentation de la class HumiditySensor, héritée de Sensor
 */

#include "HumiditySensor.hpp"

HumiditySensor::HumiditySensor()
{
    m_minValue = 5;
    m_maxValue = 31;
    m_name = "Humidity";
    m_unit = "%";
}
HumiditySensor::~HumiditySensor() = default;
HumiditySensor::HumiditySensor(const HumiditySensor& hs) = default;
HumiditySensor& HumiditySensor::operator=(const HumiditySensor& hs) = default;
