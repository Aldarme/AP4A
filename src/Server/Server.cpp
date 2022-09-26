/**
 * @author Timothe Watteau
 * @file Server.cpp
 * @date 25/09/2022
 * @brief Server class, receives and store data coming from the sensors
 */

#include "iostream"
#include "fstream"
#include "Server.hpp"

Server::Server()
{
	this->m_consoleActivation = true;
	this->m_logActivation = true;
}

Server::Server(const Server& server)
{
	this->m_consoleActivation = server.m_consoleActivation;
	this->m_logActivation = server.m_logActivation;
}

Server::~Server() = default;
Server& Server::operator=(const Server& server) = default;


void Server::consoleWrite(float measures[4], long time)
{
	std::cout << time <<	" | Temperature: " << measures[0] << "\370C" <<
						" | Humidity: " << measures[1] << "%" <<
						" | Light: " << measures[2] <<
						" | Pressure: " << measures[3] << " mbar," << std::endl;
}


void Server::fileWrite(float measures[4], long time)
{
	std::ofstream logFile("logs/mainLog.txt", std::fstream::app);
	logFile << time << "s | Temperature: " << measures[0] << "\370C" <<
					" | Humidity: " << measures[1] << "%" <<
					" | Light: " << measures[2] <<
					" | Pressure: " << measures[3] << " mbar," << std::endl;
	logFile.close();
}


void Server::DataReceive(float measures[4], long time)
{
	if (m_consoleActivation)
	{
		consoleWrite(measures, time);
	}
	if (m_logActivation)
	{
		fileWrite(measures, time);
	}
}


void Server::toggleConsoleLog() {
	this->m_consoleActivation = not this->m_consoleActivation;
}

void Server::toggleFileLog() {
	this->m_logActivation = not this->m_logActivation;
}