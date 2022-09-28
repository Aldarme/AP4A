#include "Light.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Light::Light() {
	this->setData(this->aleaGenVal());
}

int Light::aleaGenVal() {
	return rand() % 1000;
}