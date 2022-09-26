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
	float m_minValue{}, m_maxValue{};
	std::string m_logFileName;
	/**
	 * @brief Generates random value to simulate the sensor
	 * @param min minimum value
	 * @param max maximum value
	 * @return a random float between min and max
	 */
	float generateRandomValue(float min, float max);
public:
	/**
	 * @brief Orthodox canonical form constructors, destructor and affectation
	 */
	Sensor();
	Sensor(const Sensor& sensor);
	~Sensor();
	Sensor& operator=(const Sensor& sensor);

	/**
	 * Retrieves data from the sensor
	 * @return the value of the sensor
	 */
	float getData();
};

#endif //AP4A_SENSOR_HPP
