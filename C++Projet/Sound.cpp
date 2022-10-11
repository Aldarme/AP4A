
//  ∗ @author Xiyu LUO
//  ∗ @file Sound . cpp
//  ∗ @date 11/10/2022

#include "Sound.h"

// ∗ @class Sound
// ∗ @Class Sound is one of the 4 subclass of class Sensor. It is the sensor for collect the data of sound in the aircraft.

template <class T>
T Sound<T> :: aleaGenVal(){
    srand (static_cast <unsigned> (time(0)));
    int s = (rand()%(10-0+1)+0);
    // Assume that the leval of sound inside the aircraft is between 0 and 10
    // Generate random integer between 0 and 10
    return s;
}