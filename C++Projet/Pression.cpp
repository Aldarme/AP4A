
//  ∗ @author Xiyu LUO
//  ∗ @file Pression . cpp
//  ∗ @date 25/10/2022

#include "Pression.h"

// ∗ @class Pression
// ∗ @Class Pression is one of the 4 subclass of class Sensor
//    It is the sensor for collect the data of Pression in the aircraft

template <class T>
T Pression<T> :: aleaGenVal(){
    srand (static_cast <unsigned> (time(0)));
    int p = (rand()%(10-0+1)+0);
    // Assume that the leval of Pression inside the aircraft is between 0 and 10
    // Generate random integer between 0 and 10
    return p;
}