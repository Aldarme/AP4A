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
private:
	float m_lux;
public:
	Light();
	Light(const float& l);
	Light& operator=(const Light& param_l);
	//function that collect lux from Light
	Light getData();
	float getValue();
	std::string getType();
};
#endif
