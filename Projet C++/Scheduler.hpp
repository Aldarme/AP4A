#ifndef SCHEDULER_H
#define SCHEDULER_H

#pragma once

#include "Humidity.hpp"
#include "Light.hpp"
#include "Pression.hpp"
#include "Temperature.hpp"
#include "Server.hpp"
#include "Sensor.hpp"

class Scheduler{
    private:
        Humidity p_humidity;
	    Light p_light;
	    Pression p_pression;
	    Temperature p_temperature;


    public:
	Scheduler();
	Scheduler(const Scheduler& scheduler_p);
	~Scheduler();
	Scheduler& operator=(const Scheduler& scheduler_p);
	void Simulation();

};
#endif