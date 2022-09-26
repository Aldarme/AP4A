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

