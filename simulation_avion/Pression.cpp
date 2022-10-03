#include "Pression.hpp"
#include <stdlib.h>

Pression::Pression() {
    this->value = 0;
    this->type = "Pression";
    this->unity = "hPa";  
}
Pression::Pression(const Pression& p) {
    this->value = p.value;
    this->type = p.type;
    this->unity = p.unity; 
}
Pression& Pression::operator=(const Pression& p) {
    this->value = p.value; 
    this->type = p.type;
    this->unity = p.unity;
    return *this; 
}
Pression::~Pression() {
}

int Pression::aleaGenValue(){
    return (rand()%800 + 50); // pression between 50 and 850 hPa
}

std::string Pression::getType() {
    return this->type; 
}

std::string Pression::getUnity() {
    return this->unity; 
}