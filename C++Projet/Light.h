
//  ∗ @author Xiyu LUO
//  ∗ @file Light . h
//  ∗ @date 25/10/2022

// Define guards
#ifndef LIGHT_H
#define LIGHT_H

#include "Sensor.h"

using namespace std;

// ∗ @class Light
// ∗ @Class Light is one of the 4 subclass of class Sensor
//    It is the sensor for collect the data of light in the aircraft

template <class T>
class Light : public Sensor<T>{
public:
    Light(){};
    ~Light(){};
protected:
    T aleaGenVal();
    // Difine of the virtual fonction aleaGenval in subclass
};

#endif // LIGHT_H