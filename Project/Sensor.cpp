/**
 *  @author adamzm
 *  @file Sensor.h
 */

#include "Sensor.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;


// aleaGenVal() : generate random integer between 20 and 30 degree Celcius
float Temperature::aleaGenVal() {
    int min = 20;
    int max = 30;
    return (max - min) * ((float)rand()/RAND_MAX) + min;
}

// aleaGenVal() : generate random integer between 1 and 15% humidity
float Humidity::aleaGenVal() {
    int min = 1;
    int max = 15;
    return (max - min) * ((float)rand()/RAND_MAX) + min;
}

// aleaGenVal() : generate random integer between 10 and 15 PSI
int Pressure::aleaGenVal() {
    return rand() % 5 + 10;
}

// aleaGenVal() : generate random integer between 1 and 0
bool Light::aleaGenVal() {
    int i = rand() % 2 + 0;
    if (i == 0) {
        return false;
    }
    return true;   
}