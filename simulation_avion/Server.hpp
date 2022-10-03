/**
 * @author  gilles_maurer
 * @file    Server.hpp
 * @date    03/10/2022
 * @brief   Server class, write data in a file and in the console
 */

#ifndef SERVER_H
#define SERVER_H

#include "Sensor.hpp"

#include <string>

class Server 
{
    private:
    
    public:
        Server();
        Server(const Server& param);
        Server& operator=(const Server& param);
        ~Server();

        void consoleWrite(int value, std::string type, std::string unity);
        void consoleWrite();

        void fileWrite(int value, std::string type, std::string unity);
        void fileWrite();
        void resetLogs();
};


#endif // SERVER_H


