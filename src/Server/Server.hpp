/**
 * @author Timothe Watteau
 * @file Server.cpp
 * @date 25/09/2022
 * @brief Server class, receives and store data coming from the sensors
 */

#ifndef AP4A_SERVER_HPP
#define AP4A_SERVER_HPP

#include "iostream"

class Server
{
private:
	bool m_consoleActivation;
	bool m_logActivation;

	/**
	 * @brief Writes all the sensors values in the console
	 * @param measures measured values of the 0: temperature, 1: humidity, 2: light, 3: pressure
	 * @param time time of the measures
	 */
	void consoleWrite(float measures[4], long time);
	/**
	 * @brief Writes a sensor value in the console
	 * @param sensor character indicating the sensor used
	 * @param measures measured value
	 * @param time time of the measure
	 */
	template<typename T>
	void consoleWrite(std::string sensor, T measure, long time);
	/**
	 * @brief Writes all the sensors values in the main log file
	 * @param measures values of the 0: temperature, 1: humidity, 2: light, 3: pressure
	 * @param time time of the measures
	 */

	void fileWrite(float measures[4], long time);
	/**
	 * @brief Writes the value of one sensor in the corresponding log file
	 * @param sensor type of sensor (temperature, humidity, light, pressure)
	 * @param measure measure of the sensor
	 * @param time time of the measure
	 */
	template<typename T>
	void fileWrite(std::string sensor, T value, long time);

public:
	// CONSTRUCTORS
	/**
	 * @brief Default constructor
	 */
	Server();
	/**
	 * @brief Copy constructor
	 * @param server : Server object to copy into the new one
	 */
	Server(const Server& server);
	/**
	 * @brief Destructor
	 */
	~Server();

	/**
	 * @brief Equal operator, copies the server object to the caller
	 * @param server : server to copy
	 * @return a reference to the copied object
	 */
	Server& operator=(const Server& server);


	// METHODS
	/**
	 * Receives data from the sensors
	 * @param measures measures of the sensors
	 * @param time time of the measures
	 */
	void DataReceive(float measures[4], long time);
	/**
	 * Receives data from a sensor
	 * @param sensor type of sensor (temperature, humidity, light, pressure)
	 * @param measure measure of the sensor
	 * @param time time of the measure
	 */
	template<typename T>
	void DataReceive(std::string sensor, T measure, long time);
	/**
	 * Toggles the console log to true or false
	 */

	void toggleConsoleLog();
	/**
	 * Toggles the files log to true or false
	 */
	void toggleFileLog();
};

#endif //AP4A_SERVER_HPP
