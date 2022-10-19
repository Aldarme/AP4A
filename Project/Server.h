/**
 *  @author adamzm
 *  @file Server.h
 */

#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <string>

class Server {  

    public:
        // constructor
        Server() {}

        // destructor
        virtual ~Server() {}

        // consoleWrite(string, string) : show data on terminal
        void consoleWrite(std::string, std::string);

        // fileWrite(float, std::string) : write a log.txt for the datas
        void fileWrite(std::string, std::string);

        void resetFile(std::string);

};

#endif // SERVER_H