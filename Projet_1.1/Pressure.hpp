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
	private :
		float m_press;
	public:
		Pressure();
		Pressure(const float& s);
		Pressure &operator=(const Pressure& param_s);
		//function that collect decibel from Pressure
		Pressure getData();
		float getValue();
		std::string getType();
};
#endif