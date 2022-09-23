/**
 * @author choulot_hugo
 * @file Server.cpp
 * @date 17/09/2022
 * @brief Cette classe permet de recevoir les données des capteurs et de les visualiser dans la console et/ou de les stocker dans les fichiers de logs
 */

#include "Server.hpp"
#include <iostream>
#include <fstream>
#include <string>

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

    cout << "Temperature : " << this->m_temperature_test << "\n" << "Humidity : " << this->m_humidity_test << "\n" << "Light : " << this->m_light_test << "\n" << "Pression : " << this->m_pression_test << "\n" << endl;

}

/**
 * @brief Stocker les données des capteurs dans des fichiers de logs
 * @return void
 * @param
 */
void Server::fileWrite(string const cheminFichier){

    ofstream donnéesCapteurs(cheminFichier, ios::app);

    if(donnéesCapteurs){
        cout << "OK" << endl;
        donnéesCapteurs << "Temperature : " << this->m_temperature_test << "\n" << "Humidity : " << this->m_humidity_test << "\n" << "Light : " << this->m_light_test << "\n" << "Pression : " << this->m_pression_test << "\n" << endl;
    }
    else 
    {
        cout << "Erreur" << endl;
    }
}