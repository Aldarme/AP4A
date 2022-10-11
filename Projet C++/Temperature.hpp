#ifndef TEMPERATURE_H
#define TEMPERATURE_H
#include "Sensor.hpp"
#pragma once

class Temperature : public Sensor<int>{
  private:
  public:
	void sense();
	Temperature()
	{
		this->type = "temperature";
		this->value = Sensor<int>::aleaGenVal();
	}
    Temperature(const Temperature&); 
    Temperature &operator=(const Temperature&); 
	~Temperature(){};

};
#endif