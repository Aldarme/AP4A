/**
 * @author Erhart Eliott
 * @file Server.hpp
 * @date 03/10/2022
 * @brief Définition de la classe Server
 */

//DEFINE GUARDS
#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <fstream>
#include <string>

/** 
 * @class Server
 * @brief Implémentation classe Server
 */

class Server
{
public:
        /// @brief Déclaration de la forme canonique de Coplien
        Server (){} // Constructeur par défaut
        Server (const Server&){} // Constructeur par recopie
        ~Server (){} // Destructeur
        
        /**
         * @brief Ecrit les differentes données dans le terminal
         * @return Rien
         */
        void consoleWrite(int tps);

        /**
         * @brief Ecrit les différentes données dans le fichier data.txt
         * @return Rien
         */
        void fileWrite(int tps);

        /**
         * @brief Efface toutes les données du fichier data.txt
         * @return Rien
         */
        void fileClear();

        int H;
        int L;
        int P;
        int T;
};

#endif // SERVER_H