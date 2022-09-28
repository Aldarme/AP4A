/**
 * @author choulot_hugo
 * @file Server.hpp
 * @date 17/09/2022
 * @brief Cette classe permet de recevoir les données des capteurs et de les visualiser dans la console et/ou de les stocker dans les fichiers de logs
 */

//
// Define guards
#ifndef Projet_AP4A_SERVER_H
#define Projet_AP4A_SERVER_H

#include <iostream>
#include <string>
#include "Scheduler.hpp"
#include "Sensor.hpp"

/**
 * @class Server
 * @brief Cette classe permet de recevoir les données des capteurs et de les visualiser dans la console et/ou de les stcoker dans les fichiers de logs
 */
class Server
{
private:

    //attributs
    int m_temperature_test;
    int m_humidity_test;
    int m_light_test;
    int m_pression_test;

public:
    //Definition de la forme canonique

    //constructeur par défaut
    Server();

    //constructeur par valeurs
    Server(const int t, const int h, const int l, const int p);

    //constructeur par recopie
    Server(const Server& s);

    //destructeur
    ~Server();

    //operator
    Server& operator=(const Server& s);


    /**
     * @brief Visualiser les données des capteurs
     * @return void
     * @param pas de paramètres
     */
    void consoleWrite();

    /**
     * @brief Stocker les données des capteurs dans des fichiers de logs
     * @return void
     * @param
     */
    void fileWrite(const std::string cheminFichier);

    friend class Scheduler;
};

#endif // Projet_AP4A_SERVER_H