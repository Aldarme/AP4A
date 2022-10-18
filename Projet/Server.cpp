#ifndef SERVER_CPP
#define SERVER_CPP

#include "Server.hpp"
#include "Scheduler.hpp"




/**
* @brief Open files, erasing previous contents if said previous contents exist
**/

void Server::initiateFile()
{
        std::ofstream myfile;

  myfile.open ("TemperatureLog.txt", std::ofstream::out | std::ofstream::trunc);
  myfile.close();
  myfile.open ("HumidityLog.txt", std::ofstream::out | std::ofstream::trunc);
  myfile.close();
  myfile.open ("PressionLog.txt", std::ofstream::out | std::ofstream::trunc);
  myfile.close();
  myfile.open ("LightLog.txt", std::ofstream::out | std::ofstream::trunc);
  myfile.close();
}

void Server::activateConsole()
{
    std::cout << "Activating Console" << std::endl;
    this->m_consolActivation = true;
}

void Server::activateLog()
{
    std::cout << "Activating Log" << std::endl;
    this->m_logActivation = true;
}

void Server::deActivateConsole()
{
    std::cout << "De-activating Console" << std::endl;
    this->m_consolActivation = false;
}

void Server::deActivateLog()
{
    std::cout << "De-activating Log" << std::endl;
    this->m_logActivation = false;
}

void Server::activateAll()
{
    this->activateConsole();
    this->activateLog();
}

void Server::deActivateAll()
{
    this->m_consolActivation = false;
    this->m_logActivation = false;
        
}





bool Server::statusConsole()
{
    return this->m_consolActivation;
}

bool Server::statusLog()
{
    
    return this->m_logActivation;
}

#endif