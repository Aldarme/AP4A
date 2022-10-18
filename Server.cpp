/*AUTHOR TRABOULSI Rawan
Créé le 09/10/2022
SERVER*/
#include "Server.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <Windows.h>

Server::Server():m_consoleActivation(false),m_logActvation(false){
        //constructeur par defaut
}

Server::Server(bool consoleActivation_p,bool logActivation_p):m_consoleActivation(consoleActivation_p),m_logActvation(logActivation_p){
        //construvteur par paramètres
}

Server::Server(const Server & S){
        m_consoleActivation=S.m_consoleActivation;
        m_logActvation=S.m_logActvation;
}

Server &Server::operator=(const Server & S){
        m_consoleActivation=S.m_consoleActivation;
        m_logActvation=S.m_logActvation;
        return *this;

}
bool Server::getconsoleActivation(){
        return m_consoleActivation;
}
bool Server::getlogActivation(){
        return m_logActvation;
}

void Server:: setconsoleAvtivation(bool consolActivation_p){
 m_consoleActivation=consolActivation_p;

}
void Server::setlogActivation(bool logActivation_p){
        m_logActvation=logActivation_p;
}

Server:: ~Server(){

}


