#pragma once

#include "Sensor.h"

class Humidity : public Sensor {
public:
    Humidity();
protected :
	int aleaGenVal() override;
};