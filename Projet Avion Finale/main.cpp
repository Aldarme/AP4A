/**
 *  @author BIN ADNAN Muhammad Izzat Affandi
 *  @file main.cpp
 *  @date 22/10/2022
 *  @brief This is the main file for the "Projet Avion"
 */

#include "Packet.hpp"
#include "Scheduler.hpp"
#include "Sensor.hpp"
#include "Server.hpp"
#include <iostream>
#include <Windows.h>

int main()
{
    Scheduler sched;
    Temperature temp;
    Humidity hum;
    Pression pres;
    Light lig;
    Packet pack;
    int i=0;
    

    while(true)
    {
        pack.setVal(temp.aleaGenVal(),pres.aleaGenVal(),hum.aleaGenVal(),lig.aleaGenVal());
        if(i%3 == 0)
        {
            sched.sendToServerLight(pack);
        }
        if(i%2 == 0)
        {
            sched.sendToServerHum(pack);
            sched.sendToServerPres(pack);
        }
        sched.sendToServerTemp(pack);
        Sleep(1000);
        i=i+1;
    }
  
}