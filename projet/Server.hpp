/**
 * @author lois roger
 * @file Server.hpp
 * @date 05/10/2022
 * @brief écrit les différentes valeurs des capteurs dans leur fichier dédiée et dans la console
 */

#ifndef SERVER_H
#define SERVER_H
#include <string>


class Server
{
    public :
        void consolwrite(int, int, int, int);
        void filewrite(int, int, int, int);

#endif