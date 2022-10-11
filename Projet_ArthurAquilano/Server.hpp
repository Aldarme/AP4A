/**
 * @author Arthur
 * @file Server.hpp
 * @date 03/10/22
 * @brief Déclaration de la classe Server
 */

//DEFINE_GUARDS
#pragma once
#ifndef SERVER_HPP
#define SERVER_HPP

#include "DataPacket.hpp"

class Server
{
public:
    Server(): data(){};
    Server(const Server& server): data(server.data){};
    ~Server(){};

    void fileWrite();
    void consolWrite();
    void resetFile();

    DataPacket data;
};

#endif //SERVER.H