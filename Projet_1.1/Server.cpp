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
void Server::writeToFile(std::string param_name, std::string param_type, float param_data, std::string param_date)
{
	std::string fileName("Test");
	if (param_name == "P")
	{
		fileName = "logPressure.txt";
	}
	else if (param_name == "L")
	{
		fileName = "logLight.txt";
	}
	else if (param_name == "H")
	{
		fileName ="logHumidity.txt";
	}
	else if (param_name == "T")
	{
		
		fileName = "logTemperature.txt";
	}
	else
	{
		std::cout << "Error: no file name found" << std::endl;
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

void Server::getData(Pressure param_p, Light param_l, Humidity param_h, Temperature param_t)
{
	// current date and time on the current system
	time_t now = time(0);

	// convert now to string form
	std::string m_date_time = ctime(&now);
	writeToFile("P", param_p.getType(), param_p.getValue(), m_date_time);
	consoleWrite(param_p.getType(), param_p.getValue(), m_date_time);
	writeToFile("L", param_l.getType(), param_l.getValue(), m_date_time);
	consoleWrite(param_l.getType(), param_l.getValue(), m_date_time);
	writeToFile("H", param_h.getType(), param_h.getValue(), m_date_time);
	consoleWrite(param_h.getType(), param_h.getValue(), m_date_time);
	writeToFile("T", param_t.getType(), param_t.getValue(), m_date_time);
	consoleWrite(param_t.getType(), param_t.getValue(), m_date_time);
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
