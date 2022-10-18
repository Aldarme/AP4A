#pragma once
#include "sensor.hpp"


class humidity :public sensor <float>
{
private:

public:
	humidity();

	humidity(const humidity& h);

	virtual float aleaGenVal();
};