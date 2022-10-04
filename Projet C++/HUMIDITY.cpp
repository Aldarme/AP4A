#ifndef HUMIDTY_CPP
#define HUMIDITY_CPP

#include <iostream>
#include "Humidity.h"
using namespace std;

void Humidity::sense()
{
	this->value = Sensor<float>::aleaGenVal();
}
#endif