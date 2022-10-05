#include "Humidity.h"
#include <cstdlib>

Humidity::Humidity()
{
	this->setData(this->aleaGenVal());
	this->setSpecifications("Humidity","%");
}

int Humidity::aleaGenVal()
{
	return rand() % 101;
}