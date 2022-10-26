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
private:
        char answerConsole;
        char answerLogs;

public:
        /// @brief Déclaration de la forme canonique de Coplien
        Server (){} // Constructeur par défaut
        Server (const Server&){} // Constructeur par recopie
        ~Server (){} // Destructeur
        Server& operator=(const Server& server);
        
        /**
         * @brief Demande à l'utilisatuer s'il veut écrire les valeurs dans le terminal et dans les logs
         * @return Un objet de type Server avec les variables changées
         */
        Server displayChoice();

        /**
         * @brief Ecrit les differentes données dans le terminal
         * @return Rien
         * @param tps : temps en seconde
         */
        void consoleWrite(int tps);

        /**
         * @brief Ecrit les différentes données dans le fichier data.txt
         * @return Rien
         * @param tps : temps en seconde
         */
        void fileWrite(int tps);

        /**
         * @brief Efface toutes les données du fichier data.txt
         * @return Rien
         */
        void fileClear();

        float H;
        bool L;
        int P;
        float T;
};

#endif // SERVER_H