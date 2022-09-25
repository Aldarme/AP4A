/**
 * @author Timothe Watteau
 * @file Server.cpp
 * @date 25/09/2022
 * @brief Server class, receives and store data coming from the sensors
 */

#include "iostream"
#include "fstream"
#include "Server.hpp"

using namespace std;

Server::Server()
{
	this->m_consoleActivation = false;
	this->m_logActivation = false;
}

Server::Server(const Server& server)
{
	this->m_consoleActivation = server.m_consoleActivation;
	this->m_logActivation = server.m_logActivation;
}

void Server::consoleWrite(float temperature, float humidity, float light, float pressure)
{
	cout << "Temperature: " << temperature << "\370C" <<
					" | Humidity: " << humidity <<
					" | Light: " << light <<
					" | Pressure: " << pressure << " bar," << endl;
}

void Server::fileWrite(float temperature, float humidity, float light, float pressure)
{
	ofstream logFile;
	logFile.open("C:/Users/Timothe/Desktop/AP4A/TP/AP4A/src/logs/mainLog.txt", fstream::app);
	logFile << "Temperature: " << temperature << "\370C" <<
					" | Humidity: " << humidity <<
					" | Light: " << light <<
					" | Pressure: " << pressure << " bar," << endl;
	logFile.close();
}

void Server::fileWrite(char sensorType, float value)
{
	ofstream logFile;
	string logFileName = "unknown";
	switch(sensorType)
	{
		case 't':
			logFileName = "temperatureLog";
			break;
		case 'h':
			logFileName = "humidityLog";
			break;
		case 'l':
			logFileName = "lightLog";
			break;
		case 'p':
			logFileName = "pressureLog";
			break;
		default:
			break;
	}
	logFile.open("C:/Users/Timothe/Desktop/AP4A/TP/AP4A/src/logs/" + logFileName + ".txt", fstream::app);
	logFile << "Value: " << value << "," << endl;
	logFile.close();
}

Server::~Server() = default;

Server& Server::operator=(const Server& server) = default;