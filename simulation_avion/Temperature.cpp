#include "Temperature.hpp"
#include <stdlib.h>

Temperature::Temperature() {
    this->value = 0;  
    this->type = "Temperature";
    this->unity = "C";
}
Temperature::Temperature(const Temperature& param) {
    this->value = param.value; 
    this->type = param.type;
    this->unity = param.unity;
}
Temperature& Temperature::operator=(const Temperature& param) {
    this->value = param.value; 
    this->type = param.type;
    this->unity = param.unity;
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

