/**
 * @author Timothe Watteau
 * @file Humidity.hpp
 * @date 25/09/2022
 * @brief Humidity sensor
 */

#ifndef AP4A_HUMIDITY_HPP
#define AP4A_HUMIDITY_HPP

#include "Sensor.hpp"

class Humidity : public Sensor
{
public:
	/**
	 * @brief Default constructor
	 */
	Humidity();
};

#endif //AP4A_HUMIDITY_HPP