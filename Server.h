/*
 * @author raphael_perrin
 * @file Server.h
 * @date 05/10/2022
 * @brief Classe Server ayant pour objectif d'afficher l'état de chaque sensor dans la console ou dans un fichier logs
 */

#ifndef SERVER_H
#define SERVER_H

#include <iostream>

#include "Sensor.h"

class Server
{

private :
    bool m_consoleActivation;
    bool m_logActivation;

public:
    // Définition de la forme canonique
    Server();
    ~Server(){}
    Server(const Server& server_p);
    Server& operator=(const Server& server_p);

private :
    /*
    * @brief Méthode écrivant les données des sensors dans la console
    * @return void
    * @param Sensor& sensor
    */
    void consoleWrite(Sensor& sensor_p);

    /*
    * @brief Méthode écrivant les données des sensors dans un fichier logs
    * @return void
    * @param Sensor& sensor
    */
    void fileWrite(Sensor& sensor_p); 

    friend class Scheduler;
};

#endif // SERVER_H