//
// Created by rayan on 05/10/2022.
//
#include "server.h"
#include <ctime>
#include <fstream>

Server::Server() : m_consolActivation(true), m_logActivation(true) {}

Server::Server(bool consol, bool log) : m_consolActivation(consol), m_logActivation(log) {}


// Ouverture du fichier log pour l'ecriture des données
// ATTENTION /!\ : Je n'ai pas reussi à utiliser un chemin relatif pour l'ofstream, il faudra donc
// remplacer mes chemin absolu par le votre !

void Server::fileWrite(const SensorData& data)
{
    time_t temps = time(0);
    std::string date = ctime(&temps);
    date.erase(24, 25); // remove the '\n' at the end
    if(data.TypeSensor==1){
        float f = stof(data.value);
        std::cout.setf(std::ios::fixed,std::ios::floatfield);
        std::cout.precision(1);
        std::ofstream logFile("C:\\Users\\rayan\\AP4A\\projet\\sources\\log\\templog.txt", std::ios::app);
        logFile << date << "| Temperature: " << f << std::endl;
        logFile.close();
    }
    else if(data.TypeSensor==2){
        float g = stof(data.value);
        std::cout.setf(std::ios::fixed,std::ios::floatfield);
        std::cout.precision(1);
        std::ofstream logFile("C:\\Users\\rayan\\AP4A\\projet\\sources\\log\\humlog.txt", std::ios::app);
        logFile << date << " | Humidite : " << g << std::endl;
        logFile.close();
    }
    else if(data.TypeSensor==3){
        std::ofstream logFile("C:\\Users\\rayan\\AP4A\\projet\\sources\\log\\lumlog.txt", std::ios::app);
        logFile << date << " | Lumiere : " << data.value << std::endl;
        logFile.close();
    }
    else if(data.TypeSensor==4){
        std::ofstream logFile("C:\\Users\\rayan\\AP4A\\projet\\sources\\log\\prelog.txt", std::ios::app);
        logFile << date <<  " | Pression : " << data.value << std::endl;
        logFile.close();
    }
}

void Server::consolWrite(const SensorData& data)
{
    time_t t = time(0);
    std::string date = ctime(&t);
    date.erase(24, 25);
    if(data.TypeData==1){
        float f = stof(data.value);
        std::cout.setf(std::ios::fixed,std::ios::floatfield);
        std::cout.precision(1);
        std::cout << date << " | " << nomSensor[data.TypeSensor] << " : " << f << std::endl;
    }
    else if(data.TypeData==2){
        int i = stoi(data.value);
        std::cout << date << " | " << nomSensor[data.TypeSensor] << " : " << i << std::endl;
    }
    else if(data.TypeData==3){
        std::string b = data.value;
        std::cout << date << " | " << nomSensor[data.TypeSensor] << " : " << b << std::endl;
    }
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

