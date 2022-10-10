/**
 *  @author BIN ADNAN Muhammad Izzat Affandi
 *  @file Scheduler.hpp
 *  @date 6/10/2022
 *  @brief This file contains declarations of the class "Scheduler"
 */

#ifndef SCHEDULER_H
#define SCHEDULER_H
#include "Packet.hpp"
class Scheduler
{
private:
    int m_time;
public:
    Scheduler()
    {
        this->m_time = 3000;
    };
    ~Scheduler(){};
    void sendToServer(Packet packet_p);
    int getTime();
};

#endif