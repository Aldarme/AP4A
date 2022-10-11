/**
 * @author choulot_hugo
 * @file Server.cpp
 * @date 17/09/2022
 * @brief Cette classe permet de recevoir les données des capteurs et de les visualiser dans la console et/ou de les stocker dans les fichiers de logs
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

#include "Server.hpp"

using namespace std;

//constructeur par défaut
Server::Server()
{

    m_temperature_server = 0.;
    m_humidity_server = 0.;
    m_light_server = false;
    m_pression_server = 0;

}

//constructeur par valeurs
Server::Server(const float t, const float h, const bool l, const int p)
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
void Server::consoleWrite(const Temperature& t)
{
    cout << "Temperature : " << t.m_valeur << " °C" << "\n" << endl;
}

 /**
 * @brief Visualiser les données des capteurs
 * @return void
 * @param pas de paramètres
 */
void Server::consoleWrite(const Humidity& h)
{
    cout << "Humidity : " << h.m_valeur << " %" << "\n" << endl;
}

 /**
 * @brief Visualiser les données des capteurs
 * @return void
 * @param pas de paramètres
 */
void Server::consoleWrite(const Light& l)
{
    if(l.m_valeur == true){
        cout << "Light : True" << "\n" << endl;
    }
    else
    {
        cout << "Light : False" << "\n" << endl;
    }

}

 /**
 * @brief Visualiser les données des capteurs
 * @return void
 * @param pas de paramètres
 */
void Server::consoleWrite(const Pression& p)
{
    cout << "Pression : " << p.m_valeur << " hPa" << "\n" << endl;
}

/**
 * @brief Stocker les données des capteurs dans des fichiers de logs
 * @return void
 * @param
 */
void Server::fileWrite(const Temperature& t)
{
    ofstream donnéesCapteurs("C:/Users/hugoc/OneDrive/Bureau/Projet_AP4A_1.2/Temperature.csv", ios::app);

    if(donnéesCapteurs)
    {
        donnéesCapteurs << "Temperature (°C)" << ";" << t.m_valeur << endl;
    }
    else 
    {
        cout << "Erreur" << endl;
    }

}

/**
 * @brief Stocker les données des capteurs dans des fichiers de logs
 * @return void
 * @param
 */
void Server::fileWrite(const Humidity& h)
{
    ofstream donnéesCapteurs("C:/Users/hugoc/OneDrive/Bureau/Projet_AP4A_1.2/Humidity.csv", ios::app);

    if(donnéesCapteurs)
    {
        donnéesCapteurs << "Humidity (%)" << ";" << h.m_valeur << endl;
    }
    else 
    {
        cout << "Erreur" << endl;
    }

}

/**
 * @brief Stocker les données des capteurs dans des fichiers de logs
 * @return void
 * @param
 */
void Server::fileWrite(const Light& l)
{
    ofstream donnéesCapteurs("C:/Users/hugoc/OneDrive/Bureau/Projet_AP4A_1.2/Light.csv", ios::app);

    if(donnéesCapteurs)
    {
        donnéesCapteurs <<  "Light" << ";" << l.m_valeur << endl;
    }
    else 
    {
        cout << "Erreur" << endl;
    }

}

/**
 * @brief Stocker les données des capteurs dans des fichiers de logs
 * @return void
 * @param
 */
void Server::fileWrite(const Pression& p)
{
    ofstream donnéesCapteurs("C:/Users/hugoc/OneDrive/Bureau/Projet_AP4A_1.2/Pression.csv", ios::app);

    if(donnéesCapteurs)
    {
        donnéesCapteurs << "Pression (hPa)" << ";" << p.m_valeur << endl;
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

    this->m_temperature_server = sc.m_temperature_scheduler.m_valeur;
    this->m_humidity_server = sc.m_humidity_scheduler.m_valeur;
    this->m_light_server = sc.m_light_scheduler.m_valeur;
    this->m_pression_server = sc.m_pression_scheduler.m_valeur;
    
}
