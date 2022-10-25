
//  ∗ @author Xiyu LUO
//  ∗ @file Pression . h
//  ∗ @date 25/10/2022

// Define guards
#ifndef PRESSION_H
#define PRESSION_H

#include "Sensor.h"

using namespace std;

// ∗ @class Pression
// ∗ @Class Pression is one of the 4 subclass of class Sensor
//    It is the sensor for collect the data of sound in the aircraft

template <class T>
class Pression : public Sensor<T>{
public:
    Pression(){};
    ~Pression(){};
protected:
    T aleaGenVal();
    // Difine of the virtual fonction aleaGenval in subclass
};

#endif // PRESSION_H