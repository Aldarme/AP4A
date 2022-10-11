/**
 * @author Arthur
 * @file Scheduler.cpp
 * @date 03/10/22
 * @brief Implémentation de la classe Scheduler
 */

#include "Scheduler.hpp"
#include "Data.hpp"
#include "DataPacket.hpp"
#include "Server.hpp"

Scheduler Scheduler:: getData()
{
    DataTemperature temp; 
    DataHumidity hum; 
    DataLight light;
    DataPressure pres;

    dataValue.temperature = temp.getVal();
    dataValue.humidity = hum.getVal();
    dataValue.light = light.getVal();
    dataValue.pressure = pres.getVal();

    return *this;

}

void Scheduler:: sendDataToServer(Server& server)
{
    server.data = dataValue;
}

void Scheduler:: wait()
{
    int time = 1000; 
    Sleep(time);
}