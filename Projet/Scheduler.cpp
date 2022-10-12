/**
 * @author Erhart Eliott
 * @file Scheduler.cpp
 * @date 03/10/2022
 * @brief Implémentation de la classe Scheduler
 */

#include "Scheduler.hpp"
#include <windows.h>

Scheduler Scheduler::getAll()
{
    packet.H.getVal();
    packet.L.getVal();
    packet.P.getVal();
    packet.T.getVal();

    return *this;
}

void Scheduler::sendData(Server& A)
{
    A.H = packet.H.aleaVal;
    A.L = packet.L.aleaVal;
    A.P = packet.P.aleaVal;
    A.T = packet.T.aleaVal;
}

void Scheduler::wait()
{
    Sleep(1000);
}