/**
 * @author Timothe Watteau
 * @file Sensor.hpp
 * @date 25/09/2022
 * @brief Sensor class, retrieves data from the sensors processes them
 */

#include "iostream"
#include "cmath"
#include "Sensor.hpp"

float Sensor::generateRandomValue(float min, float max)
{
	return static_cast <float> (std::rand() % static_cast <int>(floor(max - min + 1) * 10)) / 10 + min;
}

Sensor::Sensor() = default;
Sensor::Sensor(const Sensor& sensor) = default;
Sensor::~Sensor() = default;

float Sensor::getData() {
	return this->generateRandomValue(this->m_minValue, this->m_maxValue);
}