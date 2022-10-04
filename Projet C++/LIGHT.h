#ifndef LIGHT_H
#define LIGHT_H
#include "SENSOR.h"
#pragma once

using namespace std;

class Light : public Sensor<bool>
{
private:
public:
	void sense();
	Light()
	{
		this->type = "light";
		this->value = Sensor<bool>::aleaGenVal();
	}
	~Light()
	{

	}
};
#endif