#include "Sensor.hpp"

#include <stdlib.h>
#include <string>

Sensor::Sensor() {
   
}

Sensor& Sensor::operator=(const Sensor& s) {
    return *this;
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
