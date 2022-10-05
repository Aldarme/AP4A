/**
 *  @author adamzm
 *  @file Scheduler.cpp
 */

#include "Scheduler.h"
#include "Sensor.h"
#include "Server.h"
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <time.h>

void Scheduler::transmitData(){
    Server server;
    Sensor *sensor;
    Temperature t;
    Humidity h;
    Pressure p;
    Light l;
    int valueT, valueH, valueP, valueL;

    srand(time(0));

    // showing the value of Temperature
    sensor = &t;
    valueT = sensor->getData();
    server.consoleWrite(valueT,"Temperature");
    server.fileWrite(valueT, "Temperature");

    // showing the value of Humidity
    sensor = &h;
    valueH = sensor->getData();
    server.consoleWrite(valueH, "Humidity");
    server.fileWrite(valueH, "Humidity");

    // showing the value of Pressure
    sensor = &p;
    valueP = sensor->getData();
    server.consoleWrite(valueP, "Pressure");
    server.fileWrite(valueP, "Pressure");

    // showing the value of Light
    sensor = &l;
    valueL = sensor->getData();
    server.consoleWrite(valueL, "Light");
    server.fileWrite(valueL, "Light");

    sleep(m_second);

}