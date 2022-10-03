#include "Light.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Light::Light() {
	this->setData(this->aleaGenVal());
	this->setSpecifications("Light");
}

int Light::aleaGenVal() {
	return rand() % 2;
}