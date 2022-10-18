#pragma once
#include "sensor.hpp"

class sound:public sensor <int>
{
private:

public:

	sound();
	
	sound(const sound& s);

	virtual int aleaGenVal();

};