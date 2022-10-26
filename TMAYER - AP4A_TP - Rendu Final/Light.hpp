/**
 * @author mayer_thibault
 * @file Light.hpp
 * @date 04/10/2022
 * @brief Light header
 */
//Light
#ifndef LIGHT_HPP
#define LIGHT_HPP
#include <string>
#include "Sensor.hpp"

class Light : public Sensor
{
public:
	Light();
	Light(const Light& l);
	Light(time_t period_p);
	Light& operator=(const Light& param_l);
	//function that collect lux from Light
	Data<bool> getData();
	std::string getType();
};
#endif
