#ifndef SERVER_H
#define SERVER_H

#include "Scheduler.hpp"
#include <iostream>

class server
{
private:
    packet m_packet;

public:
    server():m_packet(){}
    server(const server& s): m_packet(s.m_packet){}
    ~server(){}

    server getData(scheduler);
    void consolWrite();
    void fileWrite();
    void fileReset();
};

#endif //SERVER_H