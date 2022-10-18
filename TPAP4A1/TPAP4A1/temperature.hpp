#pragma once
#include "sensor.hpp"

class temperature :public sensor <float>
{
private:

public:

	temperature();

	temperature(const temperature& t);

	virtual float aleaGenVal();
};