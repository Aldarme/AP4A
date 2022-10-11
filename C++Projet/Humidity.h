
//  ∗ @author Xiyu LUO
//  ∗ @file Humidity . h
//  ∗ @date 11/10/2022

// Define guards
#ifndef HUMIDITY_H
#define HUMIDITY_H

#include "Sensor.h"

using namespace std;


// ∗ @class Humidity
// ∗ @Class Humidity is one of the 4 subclass of class Sensor. It is the sensor for collect the data of humidity in the aircraft.

template <class T>
class Humidity : public Sensor{
public:
    T aleaGenVal();
    // Difine of the virtual fonction aleaGenval in subclass
};

#endif // HUMIDITY_H