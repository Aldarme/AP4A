/**
 * @author mayer_thibault
 * @file Sensor.hpp
 * @date 04/10/2022
 * @brief Sensor header
 */
//Sensor.hpp
#ifndef SENSOR_HPP
#define SENSOR_HPP
#include <cstdlib>
#include <ctime>
#include "Data.hpp"

class Sensor
{
public:
	Sensor();
	Sensor(const Sensor& s);
	Sensor(time_t period_p);
	time_t getLastTime();
	time_t getMesurePeriod();
	void updateLastTime();

	private : 
		time_t m_mesurePeriod;
		time_t m_lastTime; 
};

#endif