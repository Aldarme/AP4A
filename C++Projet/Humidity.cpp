
//  ∗ @author Xiyu LUO
//  ∗ @file Humidity . cpp
//  ∗ @date 25/10/2022

#include "Humidity.h"

// ∗ @class Humidity
// ∗ @Class Humidity is one of the 4 subclass of class Sensor
//    It is the sensor for collect the data of humidity in the aircraft

template <class T>
T Humidity<T> :: aleaGenVal(){
    srand (static_cast <unsigned> (time(0)));
    float h = static_cast <float> (rand())/(static_cast <float> (RAND_MAX/100));
    // Assume that the humidity inside the aircraft is between 0 and 100 percent
    // Generate random float numbers between 0 and 100
    return h;
}