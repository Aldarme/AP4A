/**
 * @author Timothe Watteau
 * @file Scheduler.hpp
 * @date 25/09/2022
 * @brief Scheduler class, indicates the frequency of data retrieving and communication with the server in order to
 * store and display them
 */

#ifndef AP4A_SCHEDULER_HPP
#define AP4A_SCHEDULER_HPP

#include "ctime"
#include "Clock.hpp"
#include "../Server/Server.hpp"
#include "../Sensors/Temperature.hpp"
#include "../Sensors/Humidity.hpp"
#include "../Sensors/Light.hpp"
#include "../Sensors/Pressure.hpp"

class Scheduler
{
private:
	Clock m_clock; // Clock object to time the measures
	Server m_server; // Server to store and display the measures
	Temperature m_temperatureSensor; // Temperature sensor
	Humidity m_humiditySensor; // Humidity sensor
	Light m_lightSensor; // Light sensor
	Pressure m_pressureSensor; // Pressure sensor
	float m_measures[4] = {0, 0, 0, 0}; // Measures of the sensors
	long m_lastMeasure; // time of the least measure

public:
	/**
	 * @brief Orthodox canonical form constructors, destructor and affectation
	 */
	Scheduler();
	Scheduler(const Scheduler& scheduler);
	~Scheduler();
	Scheduler& operator=(const Scheduler& scheduler);

	/**
	 * @brief Starts the schedule, therefore the simulation
	 */
	void LaunchScheduler();
	/**
	 * @brief Asks the user if he wants to enable or disable the file and console log of the sensors
	 */
	void askUserForOutput();
	/**
	 * @brief Asks the user for the simulation duration
	 * @return The time that the simulation lasts in seconds
	 */
	long askUserForSimulationTime();
	/**
	 * @brief Retrieves all data of the sensors into the m_measures attribute
	 */
	void RetrieveAllData();
	/**
	 * Checks for a sensor if data should be transmitted at this time
	 * @param sensor sensor from which we transmit the data
	 * @param sensorName name of the sensor
	 * @param currentTime current time of the simulation
	 */
	void checkForMeasureTransmission(Sensor sensor, std::string sensorName, long currentTime);
};

#endif //AP4A_SCHEDULER_HPP
