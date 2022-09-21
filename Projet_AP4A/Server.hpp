/**
 * @author choulot_hugo
 * @file Server.hpp
 * @date 17/09/2022
 * @brief Cette classe permet de recevoir les données des capteurs et de les visualiser dans la console et/ou de les stcoker dans les fichiers de logs
 */

//
// Define guards
#ifndef Projet_AP4A_H
#define Projet_AP4A_H

#include <iostream>
#include <string>

/**
 * @enum Capteurs
 * @brief Liste les differents types de capteurs
 */
enum Capteurs {
    e_temperature,
    e_humidity,
    e_light,
    e_pression
};

/**
 * @class Server
 * @brief Cette classe permet de recevoir les données des capteurs et de les visualiser dans la console et/ou de les stcoker dans les fichiers de logs
 */
class Server
{
private:

    //attributs
    int m_temperature;
    int m_humidity;
    int m_light;
    int m_pression;

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
};

#endif // Projet_AP4A_H