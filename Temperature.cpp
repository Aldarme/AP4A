#include "Temperature.h"
#include <cstdlib>

Temperature::Temperature() {
	this->setData(this->aleaGenVal());
}

int Temperature::aleaGenVal() {
	return rand() % 22 + 18;
}