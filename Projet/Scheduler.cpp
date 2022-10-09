#include "Scheduler.hpp"
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

packet packet::operator=(const packet& p)
{
    m_temp = p.m_temp;
    m_press = p.m_press;
    m_light = p.m_light;
    m_humid = p.m_humid;
    return *this;
}

packet packet::operator=(temperature t)
{
    m_temp = t.getData();
    return *this;
}

packet packet::operator=(pressure p)
{
    m_press = p.getData();
    return *this;
}

packet packet::operator=(light_ l)
{
    m_light = l.getData();
    return *this;
}

packet packet::operator=(humidity h)
{
    m_humid = h.getData();
    return *this;
}

void scheduler::timer()
{
    Sleep(1000);
}

scheduler scheduler::getData()
{
    temperature t;
    pressure p;
    light_ l;
    humidity h;

    t.getAlea();
    p.getAlea();
    l.getAlea();
    h.getAlea();
    
    m_packet = t;
    m_packet = p;
    m_packet = l;
    m_packet = h;

    return *this;
}

packet scheduler::transferData()
{
    return m_packet;
}