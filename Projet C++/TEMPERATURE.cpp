#ifndef TEMPERATURE_CPP
#define TEMPERATURE_CPP

#include <iostream>
#include "TEMPERATURE.h"
using namespace std;

void Temperature::sense()
{
	this->value = Sensor<int>::aleaGenVal();
}
#endif