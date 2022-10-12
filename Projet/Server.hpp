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
		~Server();
		void run();
		void getData(Pressure param_s, Light param_l, Humidity param_h, Temperature param_t);
		void writeToFile(std::string param_name, std::string param_type, float param_data, std::string param_date);
		void consoleWrite(std::string param_type, float param_value, std::string param_date);
		void createFile(std::string param_name);
		bool isPathExist(const std::string& param_s);
		void createPath(const std::string& param_s);

};

#endif