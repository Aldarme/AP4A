/**
 * @file Server.cpp
 * @author Loric Ravassard
 * @brief Gestion des données reçues : affichage dans la console et/ou dans les logs 
 * en fonction du choix de l'utilisateur
 * @version 1
 * @date 2022-09-27
 */

#include "Server.hpp"
#include "Package.hpp"
#include <fstream>
#include <iostream>
#include <vector>

Server& Server::operator=(const Server& other_p)
{
  m_consolActivation = other_p.m_consolActivation;
  m_logActivation = other_p.m_logActivation;
  return *this;
}

void Server::fileWrite(Package& data_p)
{
  std::vector<data> allData = data_p.getVector();

  for(auto elem:allData)  //pour tous les éléments de allData
  {
    std::ofstream file("../logs/"+elem.name+".csv", std::ios::app);
    file << elem.date << "," << elem.value << "," << elem.unit << std::endl;
    file.close();
  }
}

void Server::consoleWrite(Package& data_p)
{
  std::vector<data> allData = data_p.getVector();

  for(auto elem:allData)  //pour tous les éléments de allData
  {
    std::cout << "[" << elem.date << "] " << elem.name << " -> " << elem.value << " " << elem.unit << std::endl;
  }
}

void Server::dataRcv(Package& data_p)
{
  if(m_consolActivation)
  {
    consoleWrite(data_p);
  }
  if(m_logActivation)
  {
    fileWrite(data_p);
  }
}

void Server::consoleActivate(bool param_p)
{
  m_consolActivation = param_p;
}

void Server::logsActivate(bool param_p)
{
  m_logActivation = param_p;
}