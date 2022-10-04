#pragma once 

#include <iostream>
#include <cstdio>
#include <fstream>
#include "Scheduler.hpp"



class Server 
{

    private :
        friend class Scheduler;
        int sec;

    public:
        Server(); //forme coplien 
        Server (const Server&) = default;
        Server &operator=(const Server&) = default;
        ~Server() = default;
        void start(); //start le serveur
        void fileWrite(int Humidity, int Temperature, int Pression, int Light);
        void consoleWrite(int Humidity, int Temperature, int Pression, int Light);
};

