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
	Clock m_clock;
	Server m_server;
	Temperature m_temperatureSensor;
	Humidity m_humiditySensor;
	Light m_lightSensor;
	Pressure m_pressureSensor;
	float m_measures[4] = {0, 0, 0, 0};
	long m_lastMeasure;

public:
	/**
	 * Default constructor
	 */
	Scheduler();
	/**
	 * Default copy constructor
	 * @param scheduler scheduler to copy
	 */
	Scheduler(const Scheduler& scheduler);
	/**
	 * Default destructor
	 */
	~Scheduler();
	/**
	 * @brief Starts the schedule, therefore the simulation
	 * @param time time to run the simulation in seconds
	 */
	void LaunchScheduler(long time);
	/**
	 * @brief Retrieves all data of the sensors into the m_measures attribute
	 */
	void RetrieveAllData();
};

#endif //AP4A_SCHEDULER_HPP
