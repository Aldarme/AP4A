//pas de using namespace dans les headers!!
/**
* @author laduguie
* @file Server.hpp
* @date 28/09/2022
* @brief Définition de la classe Server et de la structure captor_data
*/

#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <ctime>
#include <fstream>

typedef struct captor_data  //on aurait pu définir une classe à la place d'une structure mais je préfère utiliser une structure 
    {
        int pressureValue;
        float tempValue;
        float humidityValue;
        bool lightValue;
    }captor_data;

class Server
{
    private:

    public:
        std::string log;
        std::string console;

        void consoleWrite(std::string typeCapteur, struct captor_data structServerData); //on déclare les fonctions consoleWrite et fileWrite dans la classe Server
        void fileWrite(std::string typeCapteur, struct captor_data structServerData);
        void question();

        Server(); //constructeur par défaut
        Server(const Server&); //constructeur par recopie
        Server &operator=(const Server&); //operateur d'afffectation
        ~Server(){} //Destructeur
};

#endif
