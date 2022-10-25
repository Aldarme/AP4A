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
        void fileWriteTemp(Packet packet_p);
        void fileWritePres(Packet packet_p);
        void fileWriteHum(Packet packet_p);
        void fileWriteLight(Packet packet_p);
        void consolWriteTemp(Packet packet_p);
        void consolWritePres(Packet packet_p);
        void consolWriteHum(Packet packet_p);
        void consolWriteLight(Packet packet_p);
};

#endif