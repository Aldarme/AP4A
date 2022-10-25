//  ∗ @author Xiyu LUO
//  ∗ @file Sensor . cpp
//  ∗ @date 25/10/2022

#include "Scheduler.h"

using namespace std;

// ∗ @class Scheduler
// ∗ @The relationship between class Scheduler and class Sensor is aggregation. 
//    And it is the same between class Scheduler and class Server.
//    So in class Scheduler, there is four objets of Sensor and a objet of Server.
//    The objet of class scheduler is to schedule the sensors in time and collect data from the sensors and send them to the server.

template <class T>
Scheduler<T> :: Scheduler(){
    Sensor<float>* t = new Temperature<float>();
    Sensor<float>* h = new Humidity<float>();
    Sensor<bool>* l = new Light<bool>();
    Sensor<int>* p = new Pression<int>();
    sensor[0] = t;
    sensor[1] = h;
    sensor[2] = l;
    sensor[3] = p;
    // Numbering the four sensors, number one is the temperature sensor, number two is the humidity sensor
    // number three is the Light sensor, and number four is the pression sensor
    Server();
}

template <class T>
Scheduler<T> :: ~Scheduler(){
    delete sensor[];
    delete server;
}

template <class T>
void Scheduler<T> :: SendData(int i){
    server.dataRcv(sensor[i]->getData());
    //The integer i represents the sensor number
    //Call getData of the corresponding sensor and pass the generated data to the dataRcv of the server
}