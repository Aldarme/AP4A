/**
 * @author Timothe Watteau
 * @file Sensor.hpp
 * @date 25/09/2022
 * @brief Sensor class, retrieves data from the sensors processes them
 */

#include "iostream"
#include "Sensor.hpp"

float Sensor::generateRandomValue()
{
	return static_cast <float> (std::rand() % 10000) / 100;
}

Sensor::Sensor() = default;
Sensor::Sensor(const Sensor& sensor) = default;
Sensor::~Sensor() = default;

float Sensor::getData() {
	return this->generateRandomValue();
}