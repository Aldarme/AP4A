/**
 * @author mayer_thibault
 * @file Server.hpp
 * @date 04/10/2022
 * @brief Server header
 */
//Server.hpp
#ifndef SERVER_HPP
#define SERVER_HPP
#include <string>
#include "Pressure.hpp"
#include "Humidity.hpp"
#include "Light.hpp"
#include "Temperature.hpp"

class Server
{
public:
	Server();
	void print();
	//File into a file function 
	void writeToFile(std::string param_name, std::string param_type, float param_data, std::string param_date);
	void consoleWrite(std::string param_type, float param_value, std::string param_time);    
	void getData(Pressure param_p, Light param_l, Humidity param_h, Temperature param_t);
	bool isPathExist(const std::string& param_s);
};

#endif