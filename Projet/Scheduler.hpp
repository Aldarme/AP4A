#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <iostream>
#include "Sensor.hpp"

class packet
{
    friend class scheduler;
    friend class server;

private:
    int m_temp;
    int m_press;
    int m_light;
    int m_humid;

public:
    packet() : m_temp(), m_press(), m_light(), m_humid() {}
    packet(const packet &p) : m_temp(p.m_temp), m_press(p.m_press), m_light(p.m_light), m_humid(p.m_humid) {}
    ~packet(){}

    packet operator=(const packet&);
    packet operator=(temperature);
    packet operator=(pressure);
    packet operator=(light_);
    packet operator=(humidity);
};

class scheduler
{
private:
    packet m_packet;

public:
    scheduler():m_packet(){}
    scheduler(const scheduler& s):m_packet(s.m_packet){}
    ~scheduler(){}

    void timer();
    scheduler getData();
    packet transferData();
};

#endif // SCHEDULER_H