/**
 * @author Timothe Watteau
 * @file Pressure.hpp
 * @date 25/09/2022
 * @brief Pressure sensor
 */

#ifndef AP4A_PRESSURE_HPP
#define AP4A_PRESSURE_HPP

#include "Sensor.hpp"
#include "Sensor.cpp"

class Pressure : public Sensor<int>
{
public:
	/**
	 * @brief Default constructor
	 */
	Pressure();
	int generateRandomValue(int min, int max) override
	{
		return std::rand() % static_cast <int>(max - min) + min;
	}
};

#endif //AP4A_PRESSURE_HPP