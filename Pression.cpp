#include "Pression.h"
#include <cstdlib>

Pression::Pression() {
	this->setData(this->aleaGenVal());
}

int Pression::aleaGenVal() {
	return rand() % 20;
}