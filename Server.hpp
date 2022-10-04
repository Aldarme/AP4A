//pas de using namespace dans les headers!!
/**
* @author laduguie
* @file Server.hpp
* @date 28/09/2022
* @brief The server writes the data in the consol after getting them from the scheduler
*/

#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <ctime>
#include <fstream>
#include "Sensor.hpp"


class Server
{
    private:
        
    public:
        void consoleWrite(std::string typeCapteur, type value, std::string typeVal); //on déclare les fonctions consoleWrite et fileWrite dans la classe Server
        void fileWrite(std::string typeCapteur, type value, std::string typeVal);

        Server(); //constructeur par défaut
        Server(const Server&); //constructeur par recopie
        Server &operator=(const Server&); //operateur d'afffectation
        ~Server(){} //Destructeur
};

#endif
