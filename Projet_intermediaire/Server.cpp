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
#include <fstream>
#include <Server.hpp>


/**
 * @class Server
 */

class Server 
{
    public:
        void fileWrite(int Donnees, int fichier)
        {
            if (fichier == 0)
            {
                file.open("Temperature.txt",ios.out);
                file.write(Donnees);
                file.close();
            }
            else if (fichier == 1)
            {
                file.open("Humidity.txt",ios.out);
                file.write(Donnees);
                file.close();
            }
            else if (fichier == 2)
            {
                file.open("Light.txt",ios.out);
                file.write(Donnees);
                file.close();
            }
            else if (fichier == 3)
            {
                file.open("Pression.txt",ios.out);
                file.write(Donnees);
                file.close();
            }
        };
        void consolWrite(int Donnees)
        {
            cout << Donnees <<end1;
        }

};

#endif //SERVER_H