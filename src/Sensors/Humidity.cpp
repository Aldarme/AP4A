/**
 * @author Timothe Watteau
 * @file Humidity.cpp
 * @date 25/09/2022
 * @brief Humidity sensor
 */
#include "Humidity.hpp"
#include "ctime"

Humidity::Humidity()
{
	srand(time(nullptr)); // randomizing the seed
	this->m_minValue = 10;
	this->m_maxValue = 20;
	this->m_logFileName = "humidityLog";
}