/**
 * @author Timothe Watteau
 * @file Sensor.hpp
 * @date 25/09/2022
 * @brief Sensor class, retrieves data from the sensors processes them
 */

#ifndef AP4A_SENSOR_HPP
#define AP4A_SENSOR_HPP

class Sensor
{
private:
protected:
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
	 */
	Sensor(Sensor& sensor);
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
