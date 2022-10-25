
//  ∗ @author Xiyu LUO
//  ∗ @file Scheduler . h
//  ∗ @date 25/10/2022

// Define guards
#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <iostream>
#include <thread>
#include "Sensor.h"
#include "Temperature.h"
#include "Humidity.h"
#include "Light.h"
#include "Pression.h"
#include "Server.h"

using namespace std;

// ∗ @class Scheduler
// ∗ @The relationship between class Scheduler and class Sensor is aggregation
//    And it is the same between class Scheduler and class Server
//    So in class Scheduler, there is four objets of Sensor and a objet of Server
//    The objet of class scheduler is to schedule the sensors in time and collect data from the sensors and send them to the server

template <class T>
class Scheduler{
private:
    Sensor<T>* sensor[4];  //An array of pointers to sensor objects
    Server<T> server;   //An server objet
public:
    Scheduler(){};   //Default constructor
    ~Scheduler(){};    //Default destructor
    void SendData(int i);
    //Send the data collected by sensors to the server
};

#endif // SCHEDULER_H