#include "Temperature.hpp"
#include <stdlib.h>

Temperature::Temperature() {
    this->value = 0;  
}
Temperature::Temperature(const Temperature& t) {
    this->value = t.value; 
}
Temperature& Temperature::operator=(const Temperature& t) {
    this->value = t.value; 
    return *this; 
}
Temperature& Temperature::operator=(float t) {
    this->value = t; 
    return *this; 
}
Temperature::~Temperature() {
}

int Temperature::aleaGenValue(){
    return (rand()%10 + 20); //temp between 20 and 30
}

