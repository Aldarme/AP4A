#include "Humidity.hpp"
#include "stdlib.h"

#include <string>

Humidity::Humidity() {
    this->value = 0;  
    this->type = "Humidity";
    this->unity = "%";
}
Humidity::Humidity(const Humidity& param) {
    this->value = param.value; 
    this->type = param.type;
    this->unity = param.unity;
}
Humidity& Humidity::operator=(const Humidity& param) {
    this->value = param.value; 
    this->type = param.type;
    this->unity = param.unity;
    return *this; 
}
Humidity::~Humidity() {
}

int Humidity::aleaGenValue(){
    return rand()%25 + 10; //humidity between 10 and 35 
}

std::string Humidity::getType() {
    return this->type; 
}

std::string Humidity::getUnity() {
    return this->unity; 
}
