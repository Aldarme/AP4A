/**
 * @author Thibaud Leclere <thibaud.leclere@utbm.fr>
 * @file Server.cpp
 * @date 28/09/2022
 * @brief Implémentation de la class Server
 * @brief Reçoit et envoie les données des capteurs
 */

#include "Server.hpp"

Server::Server() = default;
Server::~Server() = default;
Server::Server(const Server& s) = default;
Server& Server::operator=(const Server& s) = default;

void Server::consoleWrite(SensorData data)
{
    std::cout << data.sensorName << " \t: " << data.sensorValue << " " << data.sensorUnit << std::endl;
}

void Server::fileWrite(SensorData data)
{
    std::ofstream log;
    log.open(m_logsDirectory + "/" + data.sensorName + ".txt", std::ofstream::app);
    log << data.sensorValue << " " << data.sensorUnit << std::endl;
    log.close();
}

void Server::rcvData(SensorData data)
{
    if(m_sendConsole)
    {
        consoleWrite(data);
    }
    if(m_sendLog)
    {
        fileWrite(data);
    }
}

void Server::askOutputs()
{
    std::string repConsole, repLog;

    std::cout << "Would you like to send the data to the console ? (y/n)" << std::endl << "> ";
    std::cin >> repConsole;
    while(repConsole != "y" && repConsole != "n")
    {
        std::cin.clear();
        std::cout << "Invalid input" << std::endl;
        std::cout << "Would you like to send the data to the console ? (y/n)" << std::endl << "> ";
        std::cin >> repConsole;
    }
    std::cout << std::endl;
    m_sendConsole = repConsole == "y";

    std::cout << "Would you like to send the data to the logs ? (y/n)" << std::endl << "> ";
    std::cin >> repLog;
    while(repLog != "y" && repLog != "n")
    {
        std::cin.clear();
        std::cout << "Invalid input" << std::endl;
        std::cout << "Would you like to send the data to the logs ? (y/n)" << std::endl << "> ";
        std::cin >> repLog;
    }
    std::cout << std::endl;
    m_sendLog = repLog == "y";
    
    initLogs();
}

void Server::initLogs()
{  
    std::string cmd = "mkdir -p " + m_logsDirectory + "; rm " + m_logsDirectory + "/*.txt";
    system(cmd.c_str());
}
