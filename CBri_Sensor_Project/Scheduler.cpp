/**
 * @author Clément BRICHET
 * @file Scheduler.cpp
 * @date 23/09/2022
 * @brief 
 * */

#include "Scheduler.hpp"

#include "Temperature.hpp"
#include "Humidity.hpp"
#include "Pressure.hpp"
#include "Light.hpp"

#include "Server.hpp"
#include <unistd.h>

Scheduler::Scheduler()
{
    Humidity hSensor;
    Temperature tSensor;
    Light lSensor;
    Pressure pSensor;

    Server s;

    //Change this condition later
    while(true)
    {
        hSensor.setData();
        tSensor.setData();
        lSensor.setData();
        pSensor.setData();

        s.consoleWrite(hSensor);
        s.consoleWrite(tSensor);
        s.consoleWrite(lSensor);
        s.consoleWrite(pSensor);

        s.fileWrite(hSensor);
        s.fileWrite(tSensor);
        s.fileWrite(lSensor);
        s.fileWrite(pSensor);

        sleep(2);
    }
}

Scheduler::Scheduler(const Scheduler& s)
{

}

Scheduler::~Scheduler()
{

}

Scheduler& Scheduler::operator=(const Scheduler& s)
{

}