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

	// Declaration
	enum class Sensors{PRESSURE,LIGHT,HUMIDITY,TEMPERATURE};

	// Initialisation
	Sensors P = Sensors::PRESSURE;
	Sensors L = Sensors::LIGHT;
	Sensors H = Sensors::HUMIDITY;
	Sensors T = Sensors::TEMPERATURE;
	Server();
	void print();
	//File into a file function 
	void writeToFile(Sensors type, std::string param_type, float param_data, std::string param_date);
	void consoleWrite(std::string param_type, float param_value, std::string param_time);    
	bool isPathExist(const std::string& param_s);

};

#endif