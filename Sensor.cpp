#include "Sensor.h"
#include <cstdlib>
#include <iostream>

using namespace std;

Sensor::Sensor() {
    this->data = 0;
    specs = new const char*[LENGTH];
}

Sensor::Sensor(int type) {
    this->data = type;
    specs = new const char*[LENGTH];
}

Sensor::Sensor(const Sensor& sensor) {
    this->data = sensor.data;
    specs = new const char*[LENGTH];
    if(specs){
        for(int i = 0; i < LENGTH; i++){
            this->specs[i] = sensor.specs[i];
        }
    }
}

const char** Sensor::getSpecifications() {
    return specs;
}

void Sensor::setSpecifications(const char* spec1, const char* spec2){
    this->specs[0] = spec1;
    this->specs[1] = spec2;
}

int Sensor::getData() {
    this->setData(aleaGenVal());
    return data;
}

void Sensor::setData(int data) {
    this->data = data;
}

int Sensor::aleaGenVal() {
    return rand() % 100;
}