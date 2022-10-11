#include "Server.h"

using namespace std;

Server::Server()
{
    m_consoleActivation = false;
    m_logActivation = false;
}

Server::Server(const Server& server_p)
{
    this->m_consoleActivation = server_p.m_consoleActivation;
    this->m_logActivation = server_p.m_logActivation;
}
Server& Server::operator=(const Server& server_p)
{
    this->m_consoleActivation = server_p.m_consoleActivation;
    this->m_logActivation = server_p.m_logActivation;
    return *this;
}


