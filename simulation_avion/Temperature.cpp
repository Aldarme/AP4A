#include "Temperature.hpp"
#include <stdlib.h>

Temperature::Temperature() {
    this->value = 0;  
    this->type = "Temperature";
    this->unity = "C";
}
Temperature::Temperature(const Temperature& t) {
    this->value = t.value; 
    this->type = t.type;
    this->unity = t.unity;
}
Temperature& Temperature::operator=(const Temperature& t) {
    this->value = t.value; 
    this->type = t.type;
    this->unity = t.unity;
    return *this; 
}
Temperature::~Temperature() {
}

int Temperature::aleaGenValue(){
    return (rand()%10 + 20); //temp between 20 and 30
}

std::string Temperature::getType() {
    return this->type; 
}

std::string Temperature::getUnity() {
    return this->unity; 
}

