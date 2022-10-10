/**
 *  @author BIN ADNAN Muhammad Izzat Affandi
 *  @file main.cpp
 *  @date 4/10/2022
 *  @brief This is the main file for the "Projet Avion"
 */

#include <iostream>
#include "Sensor.hpp"
#include "Packet.hpp"
#include "Scheduler.hpp"
#include "Server.hpp"
#include <Windows.h>

int main()
{
    Temperature temp;
    Humidity hum;
    Pression press;
    Light lig;
    Packet pack;
    Scheduler sched;
    while(true)
    {
        temp.aleaGenVal(22,24);
        press.aleaGenVal(11,12);
        hum.aleaGenVal(1,21);
        lig.aleaGenVal(0,1);

        pack.setVal(temp.getData(),press.getData(),hum.getData(),lig.getData());

        sched.sendToServer(pack);
        Sleep(sched.getTime());
    }
}