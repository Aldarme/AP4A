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

Server::Server(const Server& server_p):m_consolActivation(server_p.m_consolActivation),m_logActivation(server_p.m_logActivation) {}
Server::~Server() = default;

Server& Server::operator=(const Server& server_p)
{
    this->m_logActivation = server_p.m_logActivation;
    this->m_consolActivation = server_p.m_consolActivation;
    return *this;
}

void Server::toggleConsolWrite()
{
    std::string reponse;
    std::cout << "Est-ce que vous voulez écrire dans la console ? (oui/non)";
    std::cin >> reponse;
    while (reponse != "oui" && reponse != "OUI" && reponse != "non" && reponse != "NON")
    {
        std::cout << "Vous ne pouvez entrer que oui ou non, recommencer" << std::endl << "Est-ce que vous voulez écrire dans la console ? (oui/non)";
        std::cin >> reponse;
    }
    if (reponse == "oui" || reponse == "OUI")
        this->m_consolActivation = true;
    else if (reponse == "non" || reponse == "NON")
        this->m_consolActivation = false;

}

void Server::toggleLogWrite() {
    std::string reponse;
    std::cout << "Est-ce que vous voulez écrire dans les logs ? (oui/non)";
    std::cin >> reponse;
    while (reponse != "oui" && reponse != "OUI" && reponse != "non" && reponse != "NON")
    {
        std::cout << "Vous ne pouvez entrer que oui ou non, recommencer" << std::endl << "Est-ce que vous voulez écrire dans les logs ? (oui/non)";
        std::cin >> reponse;
    }
    if (reponse == "oui" || reponse == "OUI")
        this->m_logActivation = true;
    else if (reponse == "non" || reponse == "NON")
        this->m_logActivation = false;
}