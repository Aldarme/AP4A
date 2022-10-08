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

#include "Sensor.hpp"
#include "Scheduler.hpp"

class Scheduler; //permet d'utiliser Scheduler dans les méthodes de Server, autrement erreur "Scheduler has not been declared"

/**
 * @class Server
 * @brief Cette classe permet de recevoir les données des capteurs et de les visualiser dans la console et/ou de les stcoker dans les fichiers de logs
 */
class Server
{

private:

    //attributs
    float m_temperature_server;
    float m_humidity_server;
    bool m_light_server;
    int m_pression_server;

public:

    //Définition de la forme canonique

    //constructeur par défaut
    Server();

    //constructeur par valeurs
    Server(const float t, const float h, const bool l, const int p);

    //constructeur par recopie
    Server(const Server& s);

    //destructeur
    ~Server();

    //operator
    Server& operator=(const Server& s);

    /**
     * @brief Visualiser les données des capteurs
     * @return void
     * @param void
     */
    void consoleWrite();

    /**
     * @brief Stocker les données des capteurs dans des fichiers de logs
     * @return void
     * @param chemin du fichier où l'on souhaite stocker les valeurs entre ""
     */
    void fileWrite(const std::string cheminFichier);

    /**
     * @brief Permet de recevoir les données des capteurs récupérer par le Scheduler
     * @return void
     * @param Scheduler stockant les données des capteurs
     */
    void dataRCV(Scheduler& sp);

};

#endif // Projet_AP4A_SERVER_H
