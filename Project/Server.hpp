/**
 * @author Muna Ayuni MAHATHIR
 * @file Server.hpp
 * @brief This class is to receive and store all the data received from class Scheduler.
 */

#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>

class Server
{
    public:
        Server(){} //constructeur par defaut
        virtual ~Server(){} //destructeur
        Server(const Server& other){} //constructeur de recopie
        Server& operator =(const Server& s) {} //operateur d'affectation


        // fonctions
        void ConsoleWrite (std::string sensor_p,int val_p,std::string unit_p,bool activ_p);
        void fileWrite (std::string sensor_p,int val_p,std::string unit_p,bool activ_p);
        bool ActivConsole();
        bool ActivFile();

    private :
};

#endif //SERVER_HPP