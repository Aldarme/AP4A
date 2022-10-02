//
// Created by rayan on 26/09/2022.
//
#include "Server.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

using namespace std;

Server::Server()
{
    this->m_consolActivation = true;
    this->m_logActivation = true;
}

Server::Server(const Server& server)
{
    this->m_consolActivation = server.m_consolActivation;
    this->m_logActivation = server.m_logActivation;
}

Server::~Server() {
}

void Server::fileWrite(const SensorData &data) {
    string nomcapteur;
    if(data.sensorType==1){
        time_t temps = time(0);
        std::string date = ctime(&temps);
        nomcapteur = "temp";
        std::ofstream logFile(R"(C:\Users\rayan\CLionProjects\untitled72\log\)" + nomcapteur + "Log.txt", std::ios::app);
        logFile << date << "| Temperature: " << data.value << std::endl;
        logFile.close();
    }
    else if(data.sensorType==2){
        time_t temps = time(0);
        std::string date = ctime(&temps);
        nomcapteur = "hum";
        std::ofstream logFile(R"(C:\Users\rayan\CLionProjects\untitled72\log\)" + nomcapteur + "Log.txt", std::ios::app);
        logFile << date << " | Humidite : " << data.value << std::endl;
        logFile.close();
    }
    else if(data.sensorType==3){
        time_t temps = time(0);
        std::string date = ctime(&temps);
        nomcapteur = "lum";
        std::ofstream logFile(R"(C:\Users\rayan\CLionProjects\untitled72\log\)" + nomcapteur + "Log.txt", std::ios::app);
        logFile << date << " | Lumiere : " << data.value << std::endl;
        logFile.close();
    }
    else if(data.sensorType==4){
        time_t temps = time(0);
        std::string date = ctime(&temps);
        nomcapteur = "pre";
        std::ofstream logFile(R"(C:\Users\rayan\CLionProjects\untitled72\log\)" + nomcapteur + "Log.txt", std::ios::app);
        logFile << date <<  " | Pression : " << data.value << std::endl;
        logFile.close();
    }
}

void Server::dataRcv(const SensorData &data) {
    if (this->m_consolActivation){
        this->consolWrite(data);
    }
    if (this->m_logActivation){
        this->fileWrite(data);
    }
}

void Server::consolWrite(const SensorData &data) {
    time_t temps = time(0);
    std::string date = ctime(&temps);
    string nomcapteur;
    float valeur = stof(data.value);
    if(data.sensorType==1){
        nomcapteur = "Temperature";
        std::cout << date << " | " << nomcapteur << " : " << valeur << std::endl;
    }
    else if(data.sensorType==2){
        nomcapteur = "Humidite";
        std::cout << date << " | " << nomcapteur << " : " << valeur << std::endl;
    }
    else if(data.sensorType==3){
        nomcapteur = "Lumiere";
        std::cout << date << " | " << nomcapteur << " : " << valeur << std::endl;
    }
    else if(data.sensorType==4){
        nomcapteur = "Pression";
        std::cout << date << " | " << nomcapteur << " : " << valeur << std::endl;
    }
}

void operator<<(Server& server, const SensorData& data) { server.dataRcv(data); }


