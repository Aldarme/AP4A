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
  std::string string;
  std::cout << "Est-ce que vous voulez \x82crire dans la console ? (oui/non)";
  std::cin >> string;
  // Boucle de vérification avec message d'erreur
  while (string != "oui" && string != "OUI" && string != "non" && string != "NON")
  {
    std::cout << "Vous ne pouvez entrer que oui ou non, recommencer" << std::endl << "Est-ce que vous voulez \x82crire dans la console ? (oui/non)";
    std::cin >> string;
  }
  if (string == "oui" || string == "OUI")
    this->m_consolActivation = true;
  else if (string == "non" || string == "NON")
    this->m_consolActivation = false;

}

void Server::toggleLogWrite()
{
  std::string string;
  std::cout << "Est-ce que vous voulez \x82crire dans les logs ? (oui/non)";
  std::cin >> string;
  // Boucle de vérification avec message d'erreur
  while (string != "oui" && string != "OUI" && string != "non" && string != "NON")
  {
    std::cout << "Vous ne pouvez entrer que oui ou non, recommencer" << std::endl << "Est-ce que vous voulez \x82crire dans les logs ? (oui/non)";
    std::cin >> string;
  }
  if (string == "oui" || string == "OUI")
    this->m_logActivation = true;
  else if (string == "non" || string == "NON")
    this->m_logActivation = false;
}