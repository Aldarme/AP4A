#include "Scheduler.hpp"
#include <iostream>
#include "Scheduler.hpp"

Scheduler Scheduler:: getData(int time)
{ 
    dTemperature t;
    dHumidity h; 
    dLight l;
    dPressure p;

    if (time%1 == 0){
    value.temperature = t.getVal();
    value.light = l.getVal();
    value.pressure = p.getVal();
    value.humidity = h.getVal();   
    }

    return *this;
}

void Scheduler:: sendDataToServer(int time, Server& server)
{
    server.donnee.temperature = dataValue.temperature;
    server.donnee.light = dataValue.light;
    server.donnee.humidity = dataValue.humidity;
    server.donnee.pressure= dataValue.pressure;
}
void Scheduler::wait(){
    Sleep(1000);
}