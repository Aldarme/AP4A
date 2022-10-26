/**
 * @author mayer_thibault
 * @file Pressure.hpp
 * @date 04/10/2022
 * @brief Pressure header
 */
#ifndef PRESSURE_HPP
#define PRESSURE_HPP
#include <string>
#include "Sensor.hpp"

class Pressure : public Sensor
{
	public:
		Pressure();
		Pressure(const Pressure& s);
		Pressure(time_t period_p);
		Pressure &operator=(const Pressure& param_s);
		//function that collect decibel from Pressure
		Data<int> getData();
		std::string getType();
};
#endif