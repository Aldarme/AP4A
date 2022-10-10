/**
 *  @author BIN ADNAN Muhammad Izzat Affandi
 *  @file Packet.hpp
 *  @date 6/10/2022
 *  @brief This file contains declarations of the class "Server"
 */

#ifndef SERVER_H
#define SERVER_H
#include "Packet.hpp"

class Server
{
public:
        Server(){};
        ~Server(){};
        void fileWrite(Packet packet_p);
        void consolWrite(Packet packet_p);
};

#endif