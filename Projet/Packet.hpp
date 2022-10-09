#ifndef PACKET_H
#define PACKET_H

#include <iostream>

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
    packet(const packet &param_p) : m_temp(param_p.m_temp), m_press(param_p.m_press), m_light(param_p.m_light), m_humid(param_p.m_humid) {}
    ~packet(){}

    packet operator=(const packet&);
};

#endif //PACKET_H