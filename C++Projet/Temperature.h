
//  ∗ @author Xiyu LUO
//  ∗ @file Temperature . h
//  ∗ @date 11/10/2022

// Define guards
#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include "Sensor.h"

using namespace std;

// ∗ @class Temperature
// ∗ @Class Temperature is one of the 4 subclass of class Sensor. It is the sensor for collect the data of temperature in the aircraft.

template <class T>
class Temperature : public Sensor{
public:
    T aleaGenVal();
    // Difine of the virtual fonction aleaGenval in subclass
};

#endif // TEMPERATURE_H