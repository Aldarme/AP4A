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

class Temperature
{
	public:
		Temperature();
		~Temperature();
		void run();
		Temperature getData();
		float getValue();
		std::string getType();
};

#endif