#pragma once

#include "Sensor.h"

class Light : public Sensor {
public :
	Light();
protected :
	int aleaGenVal() override;
};
