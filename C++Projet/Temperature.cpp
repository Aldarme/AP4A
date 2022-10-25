
//  ∗ @author Xiyu LUO
//  ∗ @file Temperature . cpp
//  ∗ @date 25/10/2022

#include "Temperature.h"

using namespace std;

// ∗ @class Temperature
// ∗ @Class Temperature is one of the 4 subclass of class Sensor
//    It is the sensor for collect the data of temperature in the aircraft

template <class T>
T Temperature<T> :: aleaGenVal(){
    srand (static_cast <unsigned> (time(0)));
    float t = static_cast <float> (rand())/(static_cast <float> (RAND_MAX/40));
    // Assume that the temperature inside the aircraft is between 0 and 40 degrees Celsius
    // Generate random float numbers between 0 and 40
    return t;
}