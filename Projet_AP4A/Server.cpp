/**
 * @author choulot_hugo
 * @file Server.cpp
 * @date 17/09/2022
 * @brief Cette classe permet de recevoir les données des capteurs et de les visualiser dans la console et/ou de les stcoker dans les fichiers de logs
 */

#include "Server.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//constructeur par défaut
Server::Server(){
    m_temperature = 0;
    m_humidity = 0;
    m_light = 0;
    m_pression = 0;
}

//constructeur par valeurs
Server::Server(const int t, const int h, const int l, const int p){
    m_temperature = t;
    m_humidity =h;
    m_light = l;
    m_pression = p;
}

//constructeur par recopie
Server::Server(const Server& s){
    this->m_temperature = s.m_temperature;
    this->m_humidity = s.m_humidity;
    this->m_light = s.m_light;
    this->m_pression = s.m_pression;
}

//destructeur
Server::~Server(){
    cout << "Destructeur appelle\n" << endl;
}

//operator
Server& Server::operator=(const Server& s){
    this->m_temperature = s.m_temperature;
    this->m_humidity = s.m_humidity;
    this->m_light = s.m_light;
    this->m_pression = s.m_pression;

    return *this;
}

 /**
 * @brief Visualiser les données des capteurs
 * @return void
 * @param pas de paramètres
 */
void Server::consoleWrite(){

    cout << "Temperature : " << this->m_temperature << "\n" << "Humidity : " << this->m_humidity << "\n" << "Light : " << this->m_light << "\n" << "Pression : " << this->m_pression << "\n" << endl;

}

void Server::fileWrite(string const cheminFichier){

    ofstream donnéesCapteurs(cheminFichier, ios::app);

    if(donnéesCapteurs){
        cout << "OK" << endl;
        donnéesCapteurs << "Temperature : " << this->m_temperature << "\n" << "Humidity : " << this->m_humidity << "\n" << "Light : " << this->m_light << "\n" << "Pression : " << this->m_pression << "\n" << endl;
    }
    else 
    {
        cout << "Erreur" << endl;
    }
}