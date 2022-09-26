/**
 * @author Timothe Watteau
 * @file Light.cpp
 * @date 25/09/2022
 * @brief Light sensor
 */

#include "Light.hpp"
#include "ctime"


Light::Light()
{
	srand(time(nullptr)); // randomizing the seed
	this->m_minValue = 0;
	this->m_maxValue = 1;
}

bool Light::generateRandomValue()
{
	return rand() % 2;
}

bool Light::getData()
{
	return this->generateRandomValue();
}

