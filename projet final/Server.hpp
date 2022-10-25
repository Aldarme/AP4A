#ifndef SERVER_HPP
#define SERVER_HPP

#include <thread>
#include <iostream>
#include <fstream>

#include "DataPacket.hpp"


class Server
{
public:
    DataPacket data;

   
    Server(): data(){};
    Server(const Server& server): date(server.data){};
    ~Server(){};

   
    void fileWrite(int time);

    
    void consolWrite(int time);

   
  
};

#endif