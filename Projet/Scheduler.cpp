#include "Scheduler.hpp"
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

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
    
    m_packet.m_temp = t.getData();
    m_packet.m_press = p.getData();
    m_packet.m_light = l.getData();
    m_packet.m_humid = h.getData();

    return *this;
}

server scheduler::transferData(server& param_s)
{
    param_s.getData(m_packet);
    return param_s;
}