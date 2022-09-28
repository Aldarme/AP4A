#pragma once

#include "Sensor.h"

class Pression : public Sensor {
public :
	Pression();

protected :
	int aleaGenVal() override;
};
