#include "Humidity.hpp"
#include "stdlib.h"

#include <string>

Humidity::Humidity() {
    this->value = 0;  
    this->type = "Humidity";
    this->unity = "%";
}
Humidity::Humidity(const Humidity& h) {
    this->value = h.value; 
    this->type = h.type;
    this->unity = h.unity;
}
Humidity& Humidity::operator=(const Humidity& h) {
    this->value = h.value; 
    this->type = h.type;
    this->unity = h.unity;
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
