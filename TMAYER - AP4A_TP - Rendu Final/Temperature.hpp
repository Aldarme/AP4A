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
	public:
		Temperature();
		Temperature(const Temperature& temp_p);
		Temperature(time_t period_p);
		Temperature& operator=(const Temperature& param_t);
		std::string getType();
		Data<float> getData();
};

#endif