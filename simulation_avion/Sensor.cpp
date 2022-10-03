#include "Sensor.hpp"

#include <stdlib.h>
#include <string>

Sensor::Sensor() {   
}

Sensor::Sensor(const Sensor& param) {
    this->value = param.value; 
    this->type = param.type;
    this->unity = param.unity;
}

Sensor& Sensor::operator=(const Sensor& param) {
    this->value = param.value;
    this->type = param.type;
    this->unity = param.unity;
    return *this;
}

Sensor::~Sensor() {
}

int Sensor::getData() {
    return this->aleaGenValue();  
}

std::string Sensor::getSensorType() {
    return this->getType(); 
}

std::string Sensor::getSensorUnity() {
    return this->getUnity(); 
}
