
//  ∗ @author Xiyu LUO
//  ∗ @file Light . cpp
//  ∗ @date 25/10/2022

#include "Light.h"

// ∗ @class Light
// ∗ @Class Light is one of the 4 subclass of class Sensor
//    It is the sensor for collect the data of light in the aircraft

template <class T>
T Light<T> :: aleaGenVal(){
    srand (static_cast <unsigned> (time(0)));
    bool l = = rand() & 1;
    // Assuming that the status of the lights inside the aircraft are on and off
    // we use the Boolean value 1 to indicate on and 0 to indicate off
    // Generate random boolean
    // Here, I think it has a better way to deal with this problem, but I have no idea.
    return l;
}