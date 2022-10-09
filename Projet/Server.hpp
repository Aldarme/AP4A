#ifndef SERVER_H
#define SERVER_H

#include "Packet.hpp"
#include <iostream>

class server
{
private:
    packet m_packet;

public:
    server():m_packet(){}
    server(const server& param_s): m_packet(param_s.m_packet){}
    ~server(){}

    server getData(packet);
    void consolWrite();
    void fileWrite();
    void fileReset();
};

#endif //SERVER_H