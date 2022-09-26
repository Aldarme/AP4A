/**
 * @author Timothe Watteau
 * @file Scheduler.cpp
 * @date 25/09/2022
 * @brief Scheduler class, indicates the frequency of data retrieving and communication with the sensors and the server
 * in order to store and display them.
 */

#include "Scheduler.hpp"

Scheduler::Scheduler() {
	this->m_clock = *new Clock();
	this->m_server = *new Server();
	this->m_temperatureSensor = *new Temperature();
	this->m_humiditySensor = *new Humidity();
	this->m_lightSensor = *new Light();
	this->m_pressureSensor = *new Pressure();
	this->m_lastMeasure = -1;
}

Scheduler::Scheduler(const Scheduler& scheduler) = default;
Scheduler::~Scheduler() = default;
Scheduler& Scheduler::operator=(const Scheduler &scheduler) = default;

void Scheduler::LaunchScheduler()
{
	askUserForOutput();

	long simDuration = askUserForSimulationTime();

	std::cout << "Starting the simulation ..." << std::endl;

	m_clock.setStartTime();

	// The simulation keeps going until the end of the time inputted previously
	while(this->m_clock.getTime() <= simDuration)
	{
		// At each new second, logs the values using the server
		if(this->m_lastMeasure != this->m_clock.getTime())
		{
			this->m_lastMeasure = this->m_clock.getTime();
			RetrieveAllData();
			// Sends all the data to the server
			m_server.DataReceive(m_measures, this->m_clock.getTime());
		}
	}
}

void Scheduler::askUserForOutput() {
	char consoleActivation;
	char logsActivation;
	std::cout << "Do you want to activate the console write ? [Y/N] :" << std::endl;
	std::cin >> consoleActivation;
	std::cout << "Do you want to activate the log write ? [Y/N] :" << std::endl;
	std::cin >> logsActivation;

	if (consoleActivation != 'Y' and consoleActivation != 'y') // if the user says no
	{
		m_server.toggleConsoleLog(); // toggles to false, console log is set to true by default
	}
	if (logsActivation != 'Y' and logsActivation != 'y') // if the user says no
	{
		m_server.toggleFileLog(); // toggles to false, file log is set to true by default
	}
}

long Scheduler::askUserForSimulationTime() {
	long simDuration = 0;
	std::cout << "How much time (in seconds) do you want the simulation to last ? (type a negative value for an indefinite time) :" << std::endl;
	std::cin >> simDuration;
	if (simDuration < 0)
	{
		simDuration = 2147483647;
	}
	return simDuration;
}

void Scheduler::RetrieveAllData()
{
	m_measures[0] = m_temperatureSensor.getData();
	m_measures[1] = m_humiditySensor.getData();
	m_measures[2] = m_lightSensor.getData();
	m_measures[3] = m_pressureSensor.getData();
}
