//  ∗ @author Xiyu LUO
//  ∗ @file Sensor . cpp
//  ∗ @date 11/10/2022

#include "Sensor.h"

using namespace std;

// ∗ @class Sensor
// ∗ @Class Sensor is used to abstract the real sensors on the aircraft
//    It is a parent class who has four subclasses: Temperature, Humidity, Light and Sound
//    It provides a interface getData for sending the data collected by the sensors to the scheduler
//    It provides a member function aleaGenVal for generating random numbers as a way to simulate the data collected by real sensors

template <class T>
T Sensor<T> :: getData(){
    return this->aleaGenVal();
}// A interface to get the sensor data and send the data to the scheduler