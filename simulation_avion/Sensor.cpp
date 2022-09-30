#include "Sensor.hpp"

#include <stdlib.h>

Sensor::Sensor() {
   
}

Sensor& Sensor::operator=(const Sensor& s) {
    return *this;
}

int Sensor::getData() {
    return this->aleaGenValue();  
}
