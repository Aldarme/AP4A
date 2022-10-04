/**
 * @author Tontsa apala frank
 * @file Server.hpp
 * @date 25/09/2022
 * @brief Server
 */

#include <iostream>
#include <fstream>
#include <string>
#include "Sensor.hpp"
#ifndef SERVER_H
#define SERVER_H
class Server{

 private : bool m_consolActivation,m_logActivation;
    private : std::fstream inoutstream;

    public :  Server();

    public : Server(const Server& s);

   Server& operator= (const Server& s);

   public : void fileWrite(Sensor& sensor1, Sensor& sensor2, Sensor& sensor3, Sensor& sensor4);
            void consoleWrite(Sensor& sensor1, Sensor& sensor2, Sensor& sensor3, Sensor& sensor4);

~Server();


};
#endif // SERVER_H   
