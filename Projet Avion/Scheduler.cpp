/**
 *  @author BIN ADNAN Muhammad Izzat Affandi
 *  @file Sensor.cpp
 *  @date 6/10/2022
 *  @brief This file contains implementations of the class "Scheduler"
 */

#include "Scheduler.hpp"
#include "Packet.hpp"
#include "Server.hpp"

void Scheduler::sendToServer(Packet packet_p)
{
    Server aServer;
    aServer.consolWrite(packet_p);
    aServer.fileWrite(packet_p);
}

int Scheduler::getTime()
{
    return this->m_time;
}
