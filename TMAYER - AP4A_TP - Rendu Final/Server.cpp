/**
 * @author mayer_thibault
 * @file Server.cpp
 * @date 01/10/2022
 * @brief
 */

#include "Server.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

Server::Server()
{
	//ctor
}


//Need to change the name into fileWriter
//enum pour les types de capteurs
void Server::writeToFile(Sensors type, std::string param_type, float param_data, std::string param_date)
{
	std::string fileName("Test");
	switch(type)
	{
		case Sensors::PRESSURE:
			fileName = "logPressure.txt";
			break;
		case Sensors::LIGHT:
			fileName = "logLight.txt";
			break;
		case Sensors::HUMIDITY:
			fileName = "logHumidity.txt";
			break;
		case Sensors::TEMPERATURE:
			fileName = "logTemperature.txt";
			break;
		default:
			std::cout << "Unknown sensor type" << std::endl;
			break;
	}

	std::ofstream file(fileName.c_str(), std::ios::app); 	//c_str() convert every types into string
	file << param_date;
	file << std::endl;
	file << param_type;
	file << " | ";
	file << param_data;
	file << " | ";
	file << param_date;
	file << std::endl;
}

void Server::consoleWrite(std::string param_type, float param_value, std::string param_time)
{
	std::cout << param_type << " || " << param_value << " || " << param_time << std::endl;
}

bool Server::isPathExist(const std::string& s)
{
	struct stat m_buffer;
	return (stat(s.c_str(), & m_buffer) == 0);
}
