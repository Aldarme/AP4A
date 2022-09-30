#include "Light.hpp"
#include "stdlib.h"

Light::Light() {
    this->value = 0;  
}
Light::Light(const Light& l) {
    this->value = l.value; 
}
Light& Light::operator=(const Light& l) {
    this->value = l.value; 
    return *this; 
}
Light& Light::operator=(float l) {
    this->value = l; 
    return *this; 
}
Light::~Light() {
}

int Light::aleaGenValue(){
    return rand()%2; // light on or off
}

