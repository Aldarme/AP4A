/**
* @author MOhana wael
* @file : Server.hpp
* @date 27/09/2022
* @Description Declaration classe Server
*/

#include <iostream>
#include <fstream>
#include <string>
#include "Sensor.hpp"
#ifndef Server_h
#define Server_h

class Server{

    private : bool consolActivation;
    private : bool logActivation;
    private : std::fstream inoutstream;

    public :  Server();

    public : Server(const Server& autre);

   Server& operator= (const Server& autre);

   public : void fileWrite(Sensor& s1, Sensor& s2, Sensor& s3, Sensor& s4);

   public : void consoleWrite(Sensor& s1, Sensor& s2, Sensor& s3, Sensor& s4);

~Server();
};

#endif