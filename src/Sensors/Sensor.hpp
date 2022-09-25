/**
 * @author Timothe Watteau
 * @file Sensor.hpp
 * @date 25/09/2022
 * @brief Sensor class, retrieves data from the sensors processes them
 */

#ifndef AP4A_SENSOR_HPP
#define AP4A_SENSOR_HPP

#include "iostream"

class Sensor
{
private:
protected:
	std::string m_logFileName;
	/**
	 * @brief Generates random value to simulate the sensor
	 * @return a random float
	 */
	float generateRandomValue();
public:
	/**
	 * @brief Default constructor
	 */
	Sensor();
	/**
	 * @brief Default copy constructor
	 * @param sensor sensor to copy
	 */
	Sensor(const Sensor& sensor);
	/**
	 * @brief Default destructor
	 */
	~Sensor();

	/**
	 * Retrieves data from the sensor
	 * @return the value of the sensor
	 */
	float getData();
};

#endif //AP4A_SENSOR_HPP
