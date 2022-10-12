/**
 * @author mayer_thibault
 * @file Sensor.hpp
 * @date 04/10/2022
 * @brief Sensor header
 */
//Sensor.hpp
#ifndef SENSOR_HPP
#define SENSOR_HPP

class Sensor
{
	public:
		Sensor();
		~Sensor();
		void run();
		float aleaGenVal();
};

#endif