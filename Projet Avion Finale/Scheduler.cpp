/**
 *  @author BIN ADNAN Muhammad Izzat Affandi
 *  @file Sensor.cpp
 *  @date 6/10/2022
 *  @brief This file contains implementations of the class "Scheduler"
 */

#include "Scheduler.hpp"
#include "Packet.hpp"
#include "Server.hpp"

void Scheduler::sendToServerTemp(Packet packet_p)
{
    Server aServer;
    aServer.consolWriteTemp(packet_p);
    aServer.fileWriteTemp(packet_p);
}
void Scheduler::sendToServerPres(Packet packet_p)
{
    Server aServer;
    aServer.consolWritePres(packet_p);
    aServer.fileWritePres(packet_p);
}
void Scheduler::sendToServerHum(Packet packet_p)
{
    Server aServer;
    aServer.consolWriteHum(packet_p);
    aServer.fileWriteHum(packet_p);
}
void Scheduler::sendToServerLight(Packet packet_p)
{
    Server aServer;
    aServer.consolWriteLight(packet_p);
    aServer.fileWriteLight(packet_p);
}

int Scheduler::getTime()
{
    return this->m_time;
}
