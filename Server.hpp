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
        bool m_log;
        bool m_console;

        void consoleWrite(std::string typeCapteur, struct captor_data structServerData); //on déclare les fonctions consoleWrite et fileWrite dans la classe Server
        void fileWrite(std::string typeCapteur, struct captor_data structServerData);
        void question();

        Server(); //constructeur par défaut
        Server(const Server& pObjetServer)
        {
            this->m_log = pObjetServer.m_log;
            this->m_console = pObjetServer.m_log; 
        }; //constructeur par recopie
        Server &operator=(const Server& pObjetServer )
        {
            if(this->m_console == pObjetServer.m_console)
            {
                this->m_console = pObjetServer.m_console;
            }
            if(this->m_log != pObjetServer.m_log)
            {
                this->m_log = pObjetServer.m_log;
            }
            return *this;
        }; //operateur d'afffectation
        ~Server(){}; //Destructeur
};

#endif
