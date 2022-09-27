/**
 * @author Timothe Watteau
 * @file Scheduler.cpp
 * @date 25/09/2022
 * @brief Scheduler class, indicates the frequency of data retrieving and communication with the sensors and the server
 * in order to store and display them.
 */

#include "chrono"
#include "thread"
#include "Scheduler.hpp"

Scheduler::Scheduler() {
	this->m_clock = *new Clock();
	this->m_server = *new Server();
	this->m_temperatureSensor = *new Temperature();
	this->m_humiditySensor = *new Humidity();
	this->m_lightSensor = *new Light();
	this->m_pressureSensor = *new Pressure();
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

	std::thread temperatureThread(&Scheduler::logTemperature, this, simDuration);
	std::thread humidityThread(&Scheduler::logHumidity, this, simDuration);
	std::thread lightThread(&Scheduler::logLight, this, simDuration);
	std::thread pressureThread(&Scheduler::logPressure, this, simDuration);
	temperatureThread.join();
	humidityThread.join();
	lightThread.join();
	pressureThread.join();
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

long Scheduler::askUserForSimulationTime()
{
	long simDuration = 0;
	std::cout << "How much time (in seconds) do you want the simulation to last ? (type a negative value for an indefinite time) :" << std::endl;
	std::cin >> simDuration;
	if (simDuration < 0)
	{
		simDuration = 2147483647;
	}
	return simDuration;
}

void Scheduler::logTemperature(long simDuration)
{
	while(m_clock.getTime() <= simDuration) // Loops until the simulation duration is over
	{
		m_server.DataReceive("temperature", m_temperatureSensor.getUnit(), m_temperatureSensor.getData(), m_clock.getTime()); // sends the data to the server
		std::this_thread::sleep_for(std::chrono::seconds(m_temperatureSensor.getMeasurePeriod())); // Puts the thread to sleep until the next measure
	}
}

void Scheduler::logHumidity(long simDuration)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(20)); // setting some lag in each thread otherwise the console prints can be intertwined when called at the same time
	while(m_clock.getTime() <= simDuration) // Loops until the simulation duration is over
	{
		m_server.DataReceive("humidity", m_humiditySensor.getUnit(), m_humiditySensor.getData(), m_clock.getTime()); // sends the data to the server
		std::this_thread::sleep_for(std::chrono::seconds(m_humiditySensor.getMeasurePeriod())); // Puts the thread to sleep until the next measure
	}
}

void Scheduler::logLight(long simDuration)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(40)); // setting some lag in each thread otherwise the console prints can be intertwined when called at the same time
	while(m_clock.getTime() <= simDuration) // Loops until the simulation duration is over
	{
		m_server.DataReceive("light", m_lightSensor.getUnit(), m_lightSensor.getData(), m_clock.getTime()); // sends the data to the server
		std::this_thread::sleep_for(std::chrono::seconds(m_lightSensor.getMeasurePeriod())); // Puts the thread to sleep until the next measure
	}
}

void Scheduler::logPressure(long simDuration)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(60)); // setting some lag in each thread otherwise the console prints can be intertwined when called at the same time
	while(m_clock.getTime() <= simDuration) // Loops until the simulation duration is over
	{
		m_server.DataReceive("light", m_pressureSensor.getUnit(), m_pressureSensor.getData(), m_clock.getTime()); // sends the data to the server
		std::this_thread::sleep_for(std::chrono::seconds(m_pressureSensor.getMeasurePeriod())); // Puts the thread to sleep until the next measure
	}
}

void Scheduler::RetrieveAllData()
{
	m_measures[0] = m_temperatureSensor.getData();
	m_measures[1] = m_humiditySensor.getData();
	m_measures[2] = m_lightSensor.getData();
	m_measures[3] = m_pressureSensor.getData();
}
