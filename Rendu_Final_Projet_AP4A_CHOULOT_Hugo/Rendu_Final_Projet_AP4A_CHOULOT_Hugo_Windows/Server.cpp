/**
 * @author choulot_hugo
 * @file Server.cpp
 * @date 17/09/2022
 * @brief Cette classe permet de recevoir les données des capteurs et de les visualiser dans la console
 * et/ou de les stocker dans les fichiers de logs
 */

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
 * @brief Visualiser les données des capteurs de type Température
 * @return void
 * @param Temperature<float>
 */
void Server::consoleWrite(const Temperature& t)
{

    cout << "Temperature : " << t.m_valeur << " °C" << "\n" << endl;

}

 /**
 * @brief Visualiser les données des capteurs de type Humidity
 * @return void
 * @param Humidity<float>
 */
void Server::consoleWrite(const Humidity& h)
{

    cout << "Humidity : " << h.m_valeur << " %" << "\n" << endl;

}

 /**
 * @brief Visualiser les données des capteurs de type Light
 * @return void
 * @param Light<bool>
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
 * @brief Visualiser les données des capteurs de type Pression
 * @return void
 * @param Pression<int>
 */
void Server::consoleWrite(const Pression& p)
{

    cout << "Pression : " << p.m_valeur << " hPa" << "\n" << endl;

}

/**
 * @brief Stocker les données des capteurs de type Temperature dans un fichier de logs .csv
 * @return void
 * @param Temperature<float>
 */
void Server::fileWrite(const Temperature& t)
{

    ofstream donnéesCapteurs("C:/Users/hugoc/Downloads/Projet_AP4A_2.1/Rendu_Final_Projet_AP4A_CHOULOT_Hugo_Windows/Log_Temperature.csv", ios::app);

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
 * @brief Stocker les données des capteurs de type Humidity dans un fichier de logs .csv
 * @return void
 * @param Humidity<float>
 */
void Server::fileWrite(const Humidity& h)
{

    ofstream donnéesCapteurs("C:/Users/hugoc/Downloads/Projet_AP4A_2.1/Rendu_Final_Projet_AP4A_CHOULOT_Hugo_Windows/Log_Humidity.csv", ios::app);

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
 * @brief Stocker les données des capteurs de type Light dans un fichier de logs .csv
 * @return void
 * @param Light<bool>
 */
void Server::fileWrite(const Light& l)
{

    ofstream donnéesCapteurs("C:/Users/hugoc/Downloads/Projet_AP4A_2.1/Rendu_Final_Projet_AP4A_CHOULOT_Hugo_Windows/Log_Light.csv", ios::app);

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
 * @brief Stocker les données des capteurs de type Pression dans un fichier de logs .csv
 * @return void
 * @param Pression<int>
 */
void Server::fileWrite(const Pression& p)
{

    ofstream donnéesCapteurs("C:/Users/hugoc/Downloads/Projet_AP4A_2.1/Rendu_Final_Projet_AP4A_CHOULOT_Hugo_Windows/Log_Pression.csv", ios::app);

    if(donnéesCapteurs)
    {

        donnéesCapteurs << "Pression (hPa)" << ";" << p.m_valeur << endl;

    }
    else 
    {

        cout << "Erreur" << endl;

    }

}
