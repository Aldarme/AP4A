//
// Created by rayan on 05/10/2022.
//
#include "server.h"
#include <ctime>
#include <fstream>

Server::Server() : m_consolActivation(true), m_logActivation(true) {}

Server::Server(bool consol, bool log) : m_consolActivation(consol), m_logActivation(log) {}


// Ouverture du fichier log pour l'ecriture des données ( 1 seul fichier pour le rendu intermédiaire)
// ATTENTION /!\ : Je n'ai pas reussi à utiliser un chemin relatif pour l'ofstream, il faudra donc
// remplacer mon chemin absolu par le votre !

void Server::fileWrite(const SensorData& data)
{
    time_t temps = time(0);
    std::string date = ctime(&temps);
    date.erase(24, 25); // remove the '\n' at the end
    std::ofstream logFile("C:\\Users\\rayan\\Desktop\\Projet\\sources\\log\\log.txt", std::ios::app); // a changer par votre chemin absolu
    logFile << date << " | " << nomSensor[data.TypeSensor] << " : " << data.value << std::endl;
    logFile.close();
}

void Server::consolWrite(const SensorData& data)
{
    time_t t = time(0);
    std::string date = ctime(&t);
    date.erase(24, 25);
    float f = data.value;
    std::cout.setf(std::ios::fixed,std::ios::floatfield);
    std::cout.precision(1);
    std::cout << date << " | " << nomSensor[data.TypeSensor] << " : " << f << std::endl;
}

void Server::dataRcv(const SensorData& data)
{
    if (this->m_consolActivation)
        this->consolWrite(data);
    if (this->m_logActivation)
        this->fileWrite(data);
}

void Server::affichageConsole() {
    this->m_consolActivation = false;
}

void Server::ecritureLog() {
    this->m_logActivation = false ;
}

// operateur permettant de recevoir donnee
void operator<<(Server& server, const SensorData& data) { server.dataRcv(data); }

