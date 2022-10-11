
//  ∗ @author Xiyu LUO
//  ∗ @file Scheduler . h
//  ∗ @date 11/10/2022

// Define guards
#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Sensor.h"
#include "Temperature.h"
#include "Humidity.h"
#include "Light.h"
#include "Sound.h"
#include "Server.h"

using namespace std;

// ∗ @class Scheduler
// ∗ @The relationship between class Scheduler and class Sensor is aggregation. 
//    And it is the same between class Scheduler and class Server.
//    So in class Scheduler, there is a objet of Sensor and a objet of Server.
//    The objet of class scheduler is to schedule the sensors in time and collect data from the sensors and send them to the server.

template <class T>
class Scheduler{
private:
    Sensor<T>[4] sensor;  //An array to hold the sensor objects
    Server server;
public:
    Scheduler() : sensor(), server() {};   //Default constructor
    ~Scheduler(){};    //Default destructor
    void Wait();
    //Wait until all sensors have collected one round of data, and then send all four data together to the server
    void SendData();
    //Send the data collected by sensors to the server
};

#endif // SCHEDULER_H