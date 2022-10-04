#ifndef SCHEDULER_H
#define SCHEDULER_H

#pragma once

#include <iostream>
#include "TEMPERATURE.cpp"
#include "PRESSION.cpp"
#include "LIGHT.cpp"
#include "HUMIDITY.cpp"
#include "SENSOR.h"
#include "SERVER.h"

class Scheduler
{
private:
	Humidity m_humidity;
	Light m_light;
	Pression m_pression;
	Temperature m_temperature;
	int t_durer;
	void setTimeDurer();
public:
	Scheduler();
	Scheduler(const Scheduler& scheduler_p);
	~Scheduler();
	Scheduler& operator=(const Scheduler& scheduler_p);
	void Simulation();

};
#endif