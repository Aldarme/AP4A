#include "Humidity.h"
#include <cstdlib>

Humidity::Humidity() {
	this->setData(this->aleaGenVal());
}

int Humidity::aleaGenVal() {
	return rand() % 100;
}