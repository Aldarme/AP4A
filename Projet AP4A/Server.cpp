/**
 * @author Tontsa apala frank
 * @file Server.cpp
 * @date 25/09/2022
 * @brief Server
 */
#include<sstream>
#include<string.h>
#include <iostream>
#include "Server.hpp"
#include "Sensor.hpp"
#include <fstream>

Server::Server(){}    // constructeur par défaut

Server::Server(const Server& s){
    this->m_consolActivation = s.m_consolActivation;    // constructeur de récopie
    this->m_logActivation = s.m_logActivation;
 }

 Server& Server::operator=(const Server& s){
     this->m_consolActivation = s.m_consolActivation;
        this->m_logActivation = s.m_logActivation;
        return *this;
}
void Server::consoleWrite(Sensor& sensor1, Sensor& sensor2, Sensor& sensor3, Sensor& sensor4){
    std::cout << "\n" << sensor1.getData() << "\t" << sensor2.getData() << "\t"<< sensor3.getData() << "\t" << sensor4.getData(); 
   };

void Server::fileWrite(Sensor& sensor1, Sensor& sensor2, Sensor& sensor3, Sensor& sensor4){
    inoutstream.open(".\\data.txt",std::fstream::app);
    inoutstream << "\n" + std::to_string(sensor1.getData()) + "\t" + std::to_string(sensor2.getData()) + "\t" + std::to_string(sensor3.getData()) + "\t" + std::to_string(sensor4.getData());
    inoutstream.close();
        };


   

