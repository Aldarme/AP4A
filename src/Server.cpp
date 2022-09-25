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

Server::~Server() = default;

Server& Server::operator=(const Server& server) = default;

void Server::consoleWrite(float temperature, float humidity, float light, float pressure, long time)
{
	cout << time <<	" | Temperature: " << temperature << "\370C" <<
									" | Humidity: " << humidity <<
									" | Light: " << light <<
									" | Pressure: " << pressure << " bar," << endl;
}

void Server::fileWrite(float temperature, float humidity, float light, float pressure, long time)
{
	ofstream logFile;
	logFile.open("C:/Users/Timothe/Desktop/AP4A/TP/AP4A/src/logs/mainLog.txt", fstream::app);
	logFile << time << " | Temperature: " << temperature << "\370C" <<
										" | Humidity: " << humidity <<
										" | Light: " << light <<
										" | Pressure: " << pressure << " bar," << endl;
	logFile.close();
}

void Server::fileWrite(char sensorType, float value, long time)
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
	logFile << time << " | Value: " << value << "," << endl;
	logFile.close();
}

void Server::fileWrite(bool value, long time)
{
	ofstream logFile;
	logFile.open("C:/Users/Timothe/Desktop/AP4A/TP/AP4A/src/logs/lightLog.txt", fstream::app);
	logFile << time << " | Value: " << value << "," << endl;
	logFile.close();
}

void Server::fileWrite(int value, long time)
{
	ofstream logFile;
	logFile.open("C:/Users/Timothe/Desktop/AP4A/TP/AP4A/src/logs/pressureLog.txt", fstream::app);
	logFile << time << " | Value: " << value << "," << endl;
	logFile.close();
}

void Server::toggleConsoleLog() {
	this->m_consoleActivation = not this->m_consoleActivation;
}

void Server::toggleFileLog() {
	this->m_logActivation = not this->m_logActivation;
}