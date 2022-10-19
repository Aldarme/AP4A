/*
* @author Metral Greg
* @file Server.hpp
* @date 17/10/2022
* @brief serveur qui va print et créer des logs des différentes valeurs des capteurs
*/

#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <cstdio>
#include <fstream>
#include "Scheduler.hpp"



class Server 
{

    private :
        bool m_consoleActivation; //bools pour savoir si oui ou non on va utiliser les cosole/les logs
        bool m_fileActivation;

    public:
        friend class Scheduler;
        Server(); //forme coplien 
        Server (const Server &server_p);
        Server &operator=(const Server &server_p);
        virtual ~Server() = default;
        void start(); //start le serveur
        void fileWrite(std::string capteur_p, struct CaptorValues s_captor_values_p);
        void consoleWrite(std::string capteur_p, struct CaptorValues s_captor_values_p);
};

#endif
