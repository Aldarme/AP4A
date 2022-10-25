/**
 * @author Arthur
 * @file Scheduler.cpp
 * @date 03/10/22
 * @brief Implémentation de la classe Scheduler
 */

#include "Scheduler.hpp"

Scheduler Scheduler:: getData(int time)
{ 
    DataTemperature temp;
    DataHumidity hum; 
    DataLight light;
    DataPressure pres;

    if (time%3 == 0){
    dataValue.temperature = temp.getVal();
    dataValue.pressure = pres.getVal();
    }
    if (time%2 == 0){    
    dataValue.humidity = hum.getVal();
    }
    if (time%1 == 0){
    dataValue.light = light.getVal();
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