#include "Pression.h"
#include <cstdlib>

Pression::Pression() {
	this->setData(this->aleaGenVal());
	this->setSpecifications("Pression","hPa");
}

int Pression::aleaGenVal() {
	return rand() % 795 + 55;
}