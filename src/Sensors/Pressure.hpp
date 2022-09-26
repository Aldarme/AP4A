/**
 * @author Timothe Watteau
 * @file Pressure.hpp
 * @date 25/09/2022
 * @brief Pressure sensor
 */

#ifndef AP4A_PRESSURE_HPP
#define AP4A_PRESSURE_HPP

#include "Sensor.hpp"

class Pressure : public Sensor
{
private:
	/**
	 * @brief Generates a random int between min and max, overwrites the method of the Sensor class to return an int
	 */
	int generateRandomValue(int min, int max);
public:
	/**
	 * @brief Default constructor
	 */
	Pressure();

	/**
	 * @brief Retrieves data from the sensor, overwrites the method of the Sensor class to return an int
	 * @return the value of the sensor
	 */
	int getData();
};

#endif //AP4A_PRESSURE_HPP