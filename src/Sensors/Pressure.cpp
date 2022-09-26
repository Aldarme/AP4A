/**
 * @author Timothe Watteau
 * @file Pressure.cpp
 * @date 25/09/2022
 * @brief Pressure sensor
 */
#include "Pressure.hpp"
#include "ctime"

Pressure::Pressure()
{
	srand(time(nullptr)); // randomizing the seed
	this->m_minValue = 540;
	this->m_maxValue = 650;
}

int Pressure::generateRandomValue(int min, int max)
{
	return std::rand() % (max - min) + min;
}

int Pressure::getData()
{
	return this->generateRandomValue(this->m_minValue, this->m_maxValue);
}
