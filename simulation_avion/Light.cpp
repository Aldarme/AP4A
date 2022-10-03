#include "Light.hpp"
#include "stdlib.h"

Light::Light() {
    this->value = 0;  
    this->type = "Light";
    this->unity = "on/off";
}
Light::Light(const Light& param) {
    this->value = param.value; 
    this->type = param.type;
    this->unity = param.unity;
}
Light& Light::operator=(const Light& param) {
    this->value = param.value; 
    this->type = param.type;
    this->unity = param.unity;
    return *this; 
}
Light::~Light() {
}

int Light::aleaGenValue(){
    return rand()%2; // light on or off
}

std::string Light::getType() {
    return this->type; 
}

std::string Light::getUnity() {
    return this->unity; 
}

