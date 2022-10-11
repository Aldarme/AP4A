//  ∗ @author Xiyu LUO
//  ∗ @file Sensor . cpp
//  ∗ @date 11/10/2022

#include "Scheduler.h"

using namespace std;

// ∗ @class Scheduler
// ∗ @The relationship between class Scheduler and class Sensor is aggregation. 
//    And it is the same between class Scheduler and class Server.
//    So in class Scheduler, there is a objet of Sensor and a objet of Server.
//    The objet of class scheduler is to schedule the sensors in time and collect data from the sensors and send them to the server.

template <class T>
Scheduler<T> :: Scheduler(){
    sensor[0] = new Temperature;
    sensor[1] = new Humidity;
    sensor[2] = new Light;
    sensor[3] = new Sound;
}

template <class T>
void Scheduler<T> :: Wait(){
    
}

template <class T>
void Scheduler<T> :: SendData(){
    T t = sensor[0].getData();
    T h = sensor[1].getData();
    T l = sensor[2].getData();
    T s = sensor[3].getData();
    // Call fileWrite in the class server to write these four data to the log file ?
}