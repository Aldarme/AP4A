/**
 * @author Timothe Watteau
 * @file Server.cpp
 * @date 25/09/2022
 * @brief Server class, receives and store data coming from the sensors
 */

#ifndef AP4A_SERVER_HPP
#define AP4A_SERVER_HPP

class Server
{
private:
	bool m_consoleActivation;
	bool m_logActivation;

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
	 * @brief Writes all the sensors values in the console
	 * @param temperature value from temperature sensor
	 * @param humidity value from humidity sensor
	 * @param light value from light sensor
	 * @param pressure value from pressure sensor
	 */
	void consoleWrite(float temperature, float humidity, float light, float pressure);
	/**
	 * @brief Writes all the sensors values in the main log file
	 * @param temperature value from temperature sensor
	 * @param humidity value from humidity sensor
	 * @param light value from light sensor
	 * @param pressure value from pressure sensor
	 */
	void fileWrite(float temperature, float humidity, float light, float pressure);
	/**
	 * @brief Writes the value of one sensor in the corresponding log file
	 * @param sensorType first character of the name of the sensor, t : temperature, h : humidity, l : light, p : pressure
	 * @param value value of the sensor
	 */
	void fileWrite(char sensorType, float value);

};

#endif //AP4A_SERVER_HPP
