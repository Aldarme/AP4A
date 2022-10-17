#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <cstdio>
#include <fstream>
#include "Scheduler.hpp"



class Server 
{

    private :


    public:
        Server(); //forme coplien 
        Server (const Server&) = default;
        Server &operator=(const Server&) = default;
        ~Server() = default;
        std::string console; //bools pour savoir si oui ou non on va utiliser les cosole/les logs
        std::string file;
        void start(); //start le serveur
        void fileWrite(std::string Capteur, struct CaptorValues captor_values);
        void consoleWrite(std::string Capteur, struct CaptorValues captor_values);
};

#endif
