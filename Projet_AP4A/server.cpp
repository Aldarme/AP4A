/**
 * @author Jules Ferlin
 * @file server.cpp
 * @date 03/10/2022
 * @brief Fichier source contenant l'implémentation de certaine méthode de la classe Server
 */

#include "server.hpp"



Server::Server()
{
    this->m_consolActivation = true;
    this->m_logActivation = true;
}

Server::Server(const Server& param_server):m_consolActivation(param_server.m_consolActivation),m_logActivation(param_server.m_logActivation) {}
Server::~Server() = default;

Server& Server::operator=(const Server& param_server)
{
    this->m_logActivation = param_server.m_logActivation;
    this->m_consolActivation = param_server.m_consolActivation;
    return *this;
}