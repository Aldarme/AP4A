#include "Humidity.hpp"
#include "stdlib.h"

Humidity::Humidity() {
    this->value = 0;  
}
Humidity::Humidity(const Humidity& h) {
    this->value = h.value; 
}
Humidity& Humidity::operator=(const Humidity& h) {
    this->value = h.value; 
    return *this; 
}
Humidity& Humidity::operator=(float h) {
    this->value = h; 
    return *this; 
}
Humidity::~Humidity() {
}

int Humidity::aleaGenValue(){
    return rand()%25 + 10; //humidity between 10 and 35 
}

