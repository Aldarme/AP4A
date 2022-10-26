/**
 * @author Erhart Eliott
 * @file Scheduler.cpp
 * @date 03/10/2022
 * @brief Implémentation de la classe Scheduler
 */

#include "Scheduler.hpp"
#include <windows.h>

int tps = 0;

Scheduler Scheduler::getAll()
{
    packet.H.aleaVal = 35;
    packet.T.aleaVal = 25;  

    packet.H.aleaGenVal(15,50);
    packet.L.aleaGenVal(0,0);
    packet.P.aleaGenVal(80,110);
    packet.T.aleaGenVal(20,30);

    return *this;
}

void Scheduler::sendData(Server& A)
{
    
    if ((tps%1) == 0)
    {
        A.H = packet.H.aleaVal;
    }
    
    if ((tps%2) == 0)
    {
        A.L = packet.L.aleaVal;
        A.P = packet.P.aleaVal;
    }

    if ((tps%3) == 0)
    {
        A.T = packet.T.aleaVal;
    }
    tps++;

}

void Scheduler::wait()
{
    Sleep(1000);
}