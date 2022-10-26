/**
 * @file Server.cpp
 * @author Loric Ravassard
 * @brief Gestion des données reçues : affichage dans la console et/ou dans les logs 
 * en fonction du choix de l'utilisateur
 * @version 2
 * @date 2022-09-27
 */

#include "Server.hpp"

Server& Server::operator=(const Server& other_p)
{
  m_consolActivation = other_p.m_consolActivation;
  m_logActivation = other_p.m_logActivation;
  return *this;
}

void Server::consoleActivate(bool param_p)
{
  m_consolActivation = param_p;
}

void Server::logsActivate(bool param_p)
{
  m_logActivation = param_p;
}