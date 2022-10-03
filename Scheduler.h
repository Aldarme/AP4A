#pragma once

#include "Sensor.h"

#include "Temperature.h"
#include "Light.h"
#include "Humidity.h"
#include "Pression.h"

class Scheduler {
private :
	Sensor* sensor1;
	Sensor* sensor2;
	Sensor* sensor3;
	Sensor* sensor4;

public:
    Scheduler();
	Scheduler(Scheduler& scheduler);
	~Scheduler(){
		delete sensor1;
		delete sensor2;
		delete sensor3;
		delete sensor4;
	}
	Scheduler& operator=(Scheduler& scheduler);
	void clock();

private :
    void wait(float time);
};

