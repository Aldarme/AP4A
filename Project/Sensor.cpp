/**
 *  @author adamzm
 *  @file Sensor.h
 */

#include "Sensor.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// getData() : return a random value based on the sensor type
int Sensor::getData() {
    return this->aleaGenVal();
}

// aleaGenVal() : generate random integer between 20 and 30 degree Celcius
int Temperature::aleaGenVal() {
    return rand() % 10 + 20;
}

// aleaGenVal() : generate random integer between 1 and 15% humidity
int Humidity::aleaGenVal() {
    return rand() % 20 + 1;
}

// aleaGenVal() : generate random integer between 10 and 15 PSI
int Pressure::aleaGenVal() {
    return rand() % 5 + 10;
}

// aleaGenVal() : generate random integer between 1 and 0
int Light:: aleaGenVal() {
    return rand() % 2 + 0;
}