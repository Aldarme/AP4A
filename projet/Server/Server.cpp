//
// Created by rayan on 26/09/2022.
//
#include "Server.h"
#include <iostream>
#include <fstream>
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

Server& Server::operator=(const Server& server){

}

void Server::consolWrite(float temperature, float humidite, float lumiere, float pression) {
    cout << "La temperature est de : " << temperature << "\370 C" << endl;
    cout << "L'humidite est de : " << humidite << endl;
    cout << "La lumiere est de : " << lumiere << endl;
    cout << "La pression est de : " << pression << endl;
}
void Server::fileWrite(const std::string& sensor, float valeur){
    if(sensor=="temp"){
        std::ofstream logFile(R"(C:\Users\rayan\CLionProjects\untitled72\log\)" + sensor + "Log.txt", std::ios::app);
        logFile << "Temperature: " << valeur << std::endl;
        logFile.close();
    }
    else if (sensor=="hum"){
        std::ofstream logFile(R"(C:\Users\rayan\CLionProjects\untitled72\log\)" + sensor + "Log.txt", std::ios::app);
        logFile << "Humidite : " << valeur << std::endl;
        logFile.close();
    }
    else if (sensor=="lum"){
        std::ofstream logFile(R"(C:\Users\rayan\CLionProjects\untitled72\log\)" + sensor + "Log.txt", std::ios::app);
        logFile << "Lumiere: " << valeur << std::endl;
        logFile.close();
    }
    else if(sensor=="pre"){
        std::ofstream logFile(R"(C:\Users\rayan\CLionProjects\untitled72\log\)" + sensor + "Log.txt", std::ios::app);
        logFile << "Pression : " << valeur << std::endl;
        logFile.close();
    }
}

