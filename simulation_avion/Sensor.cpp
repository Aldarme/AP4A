#include "Sensor.hpp"

#include <stdlib.h>
#include <string>

Sensor::Sensor() {   
}

Sensor::Sensor(const Sensor& s) {
    this->value = s.value; 
    this->type = s.type;
    this->unity = s.unity;
}

Sensor& Sensor::operator=(const Sensor& s) {
    this->value = s.value;
    this->type = s.type;
    this->unity = s.unity;
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
