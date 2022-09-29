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
Server::Server(){
    m_temperature_test = 0;
    m_humidity_test = 0;
    m_light_test = 0;
    m_pression_test = 0;
}

//constructeur par valeurs
Server::Server(const int t, const int h, const int l, const int p){
    m_temperature_test = t;
    m_humidity_test =h;
    m_light_test = l;
    m_pression_test = p;
}

//constructeur par recopie
Server::Server(const Server& s){
    this->m_temperature_test = s.m_temperature_test;
    this->m_humidity_test = s.m_humidity_test;
    this->m_light_test = s.m_light_test;
    this->m_pression_test = s.m_pression_test;
}

//destructeur
Server::~Server(){
    cout << "Destructeur appelle\n" << endl;
}

//operator
Server& Server::operator=(const Server& s){
    this->m_temperature_test = s.m_temperature_test;
    this->m_humidity_test = s.m_humidity_test;
    this->m_light_test = s.m_light_test;
    this->m_pression_test = s.m_pression_test;

    return *this;
}

 /**
 * @brief Visualiser les données des capteurs
 * @return void
 * @param pas de paramètres
 */
void Server::consoleWrite(){

    cout << "Temperature : " << this->m_temperature_test << " °C" << "\n" << "Humidity : " << this->m_humidity_test << " %" <<"\n" << "Light : " << this->m_light_test << " lx" <<"\n" << "Pression : " << this->m_pression_test << " hPa" <<"\n" << endl;

}

/**
 * @brief Stocker les données des capteurs dans des fichiers de logs
 * @return void
 * @param
 */
void Server::fileWrite(string const cheminFichier){

    ofstream donnéesCapteurs(cheminFichier, ios::app);

    if(donnéesCapteurs){
        cout << "Ecriture\n" << endl;
        donnéesCapteurs << "Temperature (°C)" << ";" << this->m_temperature_test << ";" << "Humidity (%)" << ";" <<this->m_humidity_test << ";" << "Light (lx)" << ";" <<this->m_light_test << ";" << "Pression (hPa)" << ";" <<this->m_pression_test << endl;
    }
    else 
    {
        cout << "Erreur" << endl;
    }
}

void Server::dataRCV(Scheduler& sp){
    this->m_temperature_test = sp.m_temperature_scheduler;
    this->m_humidity_test = sp.m_humidity_scheduler;
    this->m_light_test = sp.m_light_scheduler;
    this->m_pression_test = sp.m_pression_scheduler;
}