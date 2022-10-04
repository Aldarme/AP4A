/**
 * @author Thibaud Leclere <thibaud.leclere@utbm.fr>
 * @file Server.hpp
 * @date 28/09/2022
 * @brief Définition de la class Server
 * @brief Reçoit et stock les données des capteurs
 */

// Define guards
#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <fstream>

class Server
{
public:
    //Forme canonique
    Server();
    ~Server();
    Server(const Server& s);
    Server& operator=(const Server& s);

    /**
     * @brief Ecrit les données reçues dans la console
     * @param valeurs Liste des données à écrire dans la console (0: humidity, 1: light, 2: pressure, 4: temperature)
     */
    void consoleWrite(int valeurs[]);
    
    /**
     * @brief Ecrit les données de chaque Sensor dans un fichier (dans le dossier logs)
     * @param valeurs Liste des données à écrire dans la console (0: humidity, 1: light, 2: pressure, 4: temperature)
     */
    void fileWrite(int valeurs[]);
};

#endif // SERVER_H
