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

class Server
{
public:
	Server();
	~Server();
	void print();
	//File into a file function 
	void writeToFile(std::string param_name, std::string param_type, float param_data, std::string param_date);
	void consoleWrite(std::string param_type, float param_value, std::string param_time);    
	void getData(Pressure param_p, Light param_l, Humidity param_h, Temperature param_t);
	//Function that create a file
	void createFile(std::string param_name);
	bool isPathExist(const std::string& param_s);
};

Server::Server()
{
	//ctor
}

Server::~Server()
{
	//dtor
}

void Server::createFile(std::string param_name)
{
	if (!isPathExist(param_name))
	{
		std::ofstream m_file(param_name);
		m_file.close();
	}
}

void Server::writeToFile(std::string param_name, std::string param_type, float param_data, std::string param_date)
{
	if(!isPathExist(param_name))
	{
		createFile(param_name);
	}
	std::string toWrite = param_date;
	toWrite += param_type;
	toWrite += " | ";
	toWrite += param_data;
	std::ofstream file(toWrite, std::ios::app);
}

void Server::getData(Pressure param_p, Light param_l, Humidity param_h, Temperature param_t)
{
	// current date and time on the current system
	time_t now = time(0);

	// convert now to string form
	std::string m_date_time = ctime(&now);
	writeToFile("Data.txt", param_p.getType(), param_p.getValue(), m_date_time);
	consoleWrite(param_p.getType(), param_p.getValue(), m_date_time);
	writeToFile("Data.txt", param_l.getType(), param_l.getValue(), m_date_time);
	consoleWrite(param_l.getType(), param_l.getValue(), m_date_time);
	writeToFile("Data.txt", param_h.getType(), param_h.getValue(), m_date_time);
	consoleWrite(param_h.getType(), param_h.getValue(), m_date_time);
	writeToFile("Data.txt", param_t.getType(), param_t.getValue(), m_date_time);
	consoleWrite(param_t.getType(), param_t.getValue(), m_date_time);
}

void Server::consoleWrite(std::string param_type, float param_value, std::string param_time)
{
	std::cout << param_type << param_type << "||" << param_value;
}

bool Server::isPathExist(const std::string& s)
{
	struct stat m_buffer;
	return (stat(s.c_str(), & m_buffer) == 0);
}
