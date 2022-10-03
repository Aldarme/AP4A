#ifndef SERVER_H
#define SERVER_H

#include "Sensor.hpp"

#include <string>

class Server 
{
    private:
    
    public:
        Server();
        Server(const Server& autre);
        Server& operator=(const Server& autre);
        ~Server();

        void consoleWrite(int value, std::string type, std::string unity);
        void consoleWrite();

        void fileWrite(int value, std::string type, std::string unity);
        void fileWrite();
        void resetLogs();
};


#endif // SERVER_H


