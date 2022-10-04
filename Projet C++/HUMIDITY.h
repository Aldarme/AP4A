#ifndef HUMIDITY_H
#define HUMIDITY_H
#include "SENSOR.h"
#pragma once

class Humidity : public Sensor<float>
{
	private:
	public:
		void sense();
		Humidity()
		{
			this->type = "humidity";
			this->value = Sensor<float>::aleaGenVal();
		}
		~Humidity()
		{

		}
};
#endif

