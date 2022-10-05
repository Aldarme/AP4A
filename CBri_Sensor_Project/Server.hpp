/**
 * @author BRICHET_Clement
 * @file Server.h
 * @date 23/09/2022
 * @brief 
 * */

#ifndef SERVER_H
#define SERVER_H

#include "Sensor.hpp"
#include <iostream>

/**
 * @class Server
 * @brief
 * */

class Server
{
    private:

    public:
        //Canonic functions
        Server();
        Server(const Server&);
        Server& operator=(const Server&);
        ~Server();

        /**
         * @brief
         * @return
         * @param
         * */
        template <class Type> void fileWrite(Type);

        /**
         * @brief
         * @return
         * @param
         * */
        template <class Type> void consoleWrite(Type);
};

#endif //SERVER_H