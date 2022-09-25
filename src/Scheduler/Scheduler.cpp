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

Scheduler::~Scheduler() = default;

void Scheduler::LaunchScheduler()
{
	// The simulation keeps going until the user stops the program
	while(true)
	{
		// At each new second, logs the values using the server
		if(this->m_lastMeasure != this->m_clock.getTime())
		{
			this->m_lastMeasure = this->m_clock.getTime();
			RetrieveAllData();
			m_server.fileWrite(m_measures, this->m_clock.getTime());
			m_server.consoleWrite(m_measures, this->m_clock.getTime());
		}
	}
}

void Scheduler::RetrieveAllData()
{
	m_measures[0] = m_temperatureSensor.getData();
	m_measures[1] = m_humiditySensor.getData();
	m_measures[2] = m_lightSensor.getData();
	m_measures[3] = m_pressureSensor.getData();
}
