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
#include "../Server.hpp"
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

public:
	Scheduler();
	~Scheduler();

	void LaunchScheduler();
};

#endif //AP4A_SCHEDULER_HPP