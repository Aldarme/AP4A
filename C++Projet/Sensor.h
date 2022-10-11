
//  ∗ @author Xiyu LUO
//  ∗ @file Sensor . h
//  ∗ @date 11/10/2022

// Define guards
#ifndef SENSOR_H
#define SENSOR_H

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// ∗ @class Sensor
// ∗ @Class Sensor is used to abstract the real sensors on the aircraft
//    It is a parent class who has four subclasses: Temperature, Humidity, Light and Sound
//    It provides a interface getData for sending the data collected by the sensors to the scheduler
//    It provides a member function aleaGenVal for generating random numbers as a way to simulate the data collected by real sensors


template <class T>
class Sensor{
public:
    Sensor(){};   //Default constructor
    ~Sensor(){};    //Default destructor
    T getData(); 
    // A interface to get the sensor data and send the data to the scheduler
protected:
    //Define member functions as protected so that only the class itself and its subclasses can call these functions
    virtual T aleaGenVal(); 
    //Used to generate random numbers. 
    //Function declaration. It is virtual because it will be define in subclasses
};

#endif // SENSOR_H