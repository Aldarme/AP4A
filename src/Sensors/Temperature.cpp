/**
 * @author Timothe Watteau
 * @file Temperature.cpp
 * @date 25/09/2022
 * @brief Temperature sensor
 */
#include "Temperature.hpp"
#include "ctime"

Temperature::Temperature()
{
	srand(time(nullptr)); // randomizing the seed
	this->m_minValue = -15;
	this->m_maxValue = 0;
}

