#include "Sensor.h"
#include <cstdlib>
#include <iostream>

using namespace std;

Sensor::Sensor() {
    this->data = 0;
}

Sensor::Sensor(int type) {
    this->data = type;
}

Sensor::Sensor(const Sensor& sensor) {
    this->data = sensor.data;
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