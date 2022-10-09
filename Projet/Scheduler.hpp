#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <iostream>
#include "Temperature.hpp"
#include "Pressure.hpp"
#include "Light.hpp"
#include "Humidity.hpp"
#include "Packet.hpp"
#include "Server.hpp"

class scheduler
{
private:
    packet m_packet;

public:
    scheduler():m_packet(){}
    scheduler(const scheduler& param_s):m_packet(param_s.m_packet){}
    ~scheduler(){}

    void timer();
    scheduler getData();
    server transferData(server&);
};

#endif // SCHEDULER_H