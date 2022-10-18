/**
 * @author Cameron ROCHEBILLARD
 * @file Server.cpp
 * @date 4/10/2022
 * @brief permet de recevoir les donnees provenants des capteur 
 */

 //
 //Define guards 
 #ifndef SERVER_H
 #define SERVER_H

#include <iostream>
#include <string>
#include <cstdio>
#include "Server.hpp"


/**
 * @class Server
 */

template <class T> class Server
{
    public:

        void consolWrite(int Donnees)
        {
            using std::cout;
            using std::endl;

            cout << Donnees <<endl;
        }


        virtual fileWrite(T Donnees, int fichier)
        {
            if (fichier == 0)
            {
                freopen( "Temperature.txt", "w", stdout );
            }

            else if (fichier == 1)
            {
                freopen( "Humidity.txt", "w", stdout );
            }

            else if (fichier == 2)
            {
                freopen( "Light.txt", "w", stdout );
            }
            else if (fichier == 3)
            {
                freopen( "Pression.txt", "w", stdout );
            }
            consolWrite(Donnees);
        };


};

#endif //SERVER_H