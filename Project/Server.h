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
        Server(){}

        // destructor
        ~Server() {}

        // methods

        // consoleWrite(char) : show on terminal the data
        void consoleWrite(int, std::string);

        // fileWrite(char) : write a log.txt with the data as values
        void fileWrite(int, std::string);

};

#endif // SERVER_H