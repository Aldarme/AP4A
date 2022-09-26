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
	return static_cast <float> (std::rand() % static_cast <int>(floor(max - min) * 10)) / 10 + min;
}

Sensor::Sensor()
{
	this->m_unit = "";
	this->m_measuresPeriod = 1;
	this->m_minValue = 0;
	this->m_maxValue = 1;
}
Sensor::Sensor(const Sensor& sensor) = default;
Sensor::~Sensor() = default;
Sensor& Sensor::operator=(const Sensor &sensor) = default;

float Sensor::getData()
{
	return this->generateRandomValue(this->m_minValue, this->m_maxValue);
}

int Sensor::getMeasurePeriod()
{
	return this->m_measuresPeriod;
}

std::string Sensor::getUnit()
{
	return this->m_unit;
}
