//
// Created by Jules Ferlin on 24/09/2022.
//

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