/**
 * @author mayer_thibault
 * @file Temperature.hpp
 * @date 04/10/2022
 * @brief Temperature header
 */
//Temperature.hpp
#ifndef TEMPERATURE_HPP
#define TEMPERATURE_HPP
#include <string>
#include <cstdlib>
#include <iostream>
#include "Sensor.hpp"

class Temperature : public Sensor
{
	private:
	  float m_kelvin;
	public:
		Temperature();
		Temperature(const float& t);
		Temperature& operator=(const Temperature& param_t);
		void run();
		Temperature getData();
		float getValue();
		std::string getType();
};

#endif