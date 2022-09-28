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
    void wait(float time);
};

