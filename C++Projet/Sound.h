
//  ∗ @author Xiyu LUO
//  ∗ @file Sound . h
//  ∗ @date 11/10/2022

// Define guards
#ifndef SOUND_H
#define SOUND_H

#include "Sensor.h"

using namespace std;

// ∗ @class Sound
// ∗ @Class Sound is one of the 4 subclass of class Sensor. It is the sensor for collect the data of sound in the aircraft.

template <class T>
class Sound : public Sensor{
public:
    T aleaGenVal();
    // Difine of the virtual fonction aleaGenval in subclass
};

#endif // SOUND_H