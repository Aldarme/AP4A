/**
 * @author choulot_hugo
 * @file Server.cpp
 * @date 17/09/2022
 * @brief Cette classe permet de recevoir les données des capteurs et de les visualiser dans la console et/ou de les stocker dans les fichiers de logs
 */

#include <iostream>
#include <fstream>
#include <string>

#include "Scheduler.hpp"
#include "Sensor.hpp"
#include "Server.hpp"

using namespace std;

//constructeur par défaut
Server::Server()
{

    m_temperature_server = 0;
    m_humidity_server = 0;
    m_light_server = 0;
    m_pression_server = 0;

}

//constructeur par valeurs
Server::Server(const int t, const int h, const int l, const int p)
{

    m_temperature_server = t;
    m_humidity_server =h;
    m_light_server = l;
    m_pression_server = p;

}

//constructeur par recopie
Server::Server(const Server& s)
{

    this->m_temperature_server = s.m_temperature_server;
    this->m_humidity_server = s.m_humidity_server;
    this->m_light_server = s.m_light_server;
    this->m_pression_server = s.m_pression_server;

}

//destructeur
Server::~Server()
{

    cout << "Destructeur appelle\n" << endl;

}

//operator
Server& Server::operator=(const Server& s)
{

    this->m_temperature_server = s.m_temperature_server;
    this->m_humidity_server = s.m_humidity_server;
    this->m_light_server = s.m_light_server;
    this->m_pression_server = s.m_pression_server;

    return *this;

}

 /**
 * @brief Visualiser les données des capteurs
 * @return void
 * @param pas de paramètres
 */
void Server::consoleWrite()
{

    cout << "Temperature : " << this->m_temperature_server << " °C" << "\n" << "Humidity : "
    << this->m_humidity_server << " %" << "\n" << "Light : " << this->m_light_server << " lx" <<
     "\n" << "Pression : " << this->m_pression_server << " hPa" << "\n" << endl;

}

/**
 * @brief Stocker les données des capteurs dans des fichiers de logs
 * @return void
 * @param
 */
void Server::fileWrite(string const cheminFichier)
{

    ofstream donnéesCapteurs(cheminFichier, ios::app);

    if(donnéesCapteurs)
    {

        cout << "Ecriture\n" << endl;
        donnéesCapteurs << "Temperature (°C)" << ";" << this->m_temperature_server << ";"
        << "Humidity (%)" << ";" <<this->m_humidity_server << ";" << "Light (lx)" << ";"
        <<this->m_light_server << ";" << "Pression (hPa)" << ";" <<this->m_pression_server << endl;

    }
    else 
    {

        cout << "Erreur" << endl;

    }

}

/**
 * @brief Permet de recevoir les données des capteurs récupérer par le Scheduler
 * @return void
 * @param Scheduler stockant les données des capteurs
 */
void Server::dataRCV(Scheduler& sc)
{

    this->m_temperature_server = sc.m_temperature_scheduler;
    this->m_humidity_server = sc.m_humidity_scheduler;
    this->m_light_server = sc.m_light_scheduler;
    this->m_pression_server = sc.m_pression_scheduler;
    
}