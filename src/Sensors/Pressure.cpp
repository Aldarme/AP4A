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
	this->m_logFileName = "pressureLog";
}

