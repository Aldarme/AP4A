#include "Temperature.h"
#include <cstdlib>

Temperature::Temperature() {
	this->setData(this->aleaGenVal());
	this->setSpecifications("Temperature","degrees Celsius");
}

int Temperature::aleaGenVal() {
	return rand() % 2 + 23;
}