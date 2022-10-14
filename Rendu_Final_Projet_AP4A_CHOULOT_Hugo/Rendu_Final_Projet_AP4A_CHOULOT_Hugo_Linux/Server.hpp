/**
 * @author choulot_hugo
 * @file Server.hpp
 * @date 17/09/2022
 * @brief Cette classe permet de recevoir les données des capteurs et de les visualiser dans la console
 * et/ou de les stocker dans les fichiers de logs
 */

//
// Define guards
#ifndef Projet_AP4A_SERVER_H
#define Projet_AP4A_SERVER_H

#include <iostream>
#include <fstream>

#include "Scheduler.hpp"
#include "Temperature.hpp"
#include "Humidity.hpp"
#include "Light.hpp"
#include "Pression.hpp"

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
    * @brief Visualiser les données des capteurs de type Température
    * @return void
    * @param Temperature<float>
    */
    void consoleWrite(const Temperature& t);

     /**
    * @brief Visualiser les données des capteurs de type Humidity
    * @return void
    * @param Humidity<float>
    */
    void consoleWrite(const Humidity& h);

     /**
    * @brief Visualiser les données des capteurs de type Light
    * @return void
    * @param Light<bool>
    */
    void consoleWrite(const Light& l);

     /**
    * @brief Visualiser les données des capteurs de type Pression
    * @return void
    * @param Pression<int>
    */
    void consoleWrite(const Pression& p);

    /**
    * @brief Stocker les données des capteurs de type Temperature dans un fichier de logs .csv
    * @return void
    * @param Temperature<float>
    */
    void fileWrite(const Temperature& t);

    /**
    * @brief Stocker les données des capteurs de type Humidity dans un fichier de logs .csv
    * @return void
    * @param Humidity<float>
    */
    void fileWrite(const Humidity& h);

    /**
    * @brief Stocker les données des capteurs de type Light dans un fichier de logs .csv
    * @return void
    * @param Light<bool>
    */
    void fileWrite(const Light& l);

    /**
    * @brief Stocker les données des capteurs de type Pression dans un fichier de logs .csv
    * @return void
    * @param Pression<int>
    */
    void fileWrite(const Pression& p);

};

#endif // Projet_AP4A_SERVER_H
