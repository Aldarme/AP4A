/**
 * @author Pierre Schneiderlin
 * @file Server.cpp
 * @date 22/09/2022
 * @brief fichier source contenant l'implémentation des méthodes de la classe Server (voir "Server.hpp")
 */

#include "Server.hpp"

using namespace std;

Server& Server::operator=(const Server& s)
{
    this->m_consolActivation=s.m_consolActivation;
    this->m_logActivation=s.m_logActivation;
    return (*this);
}

bool Server::getConsolActivation() const
{
    return m_consolActivation;
}

bool Server::getLogActivation() const
{
    return m_logActivation;
}

void Server::setConsolActivation(bool setLog)
{
    m_consolActivation=setLog;
}

void Server::setLogActivation(bool setConsol)
{
    m_logActivation=setConsol;
}

ostream& operator<<(ostream& os, Server& s)
{
    os<<"\tconsolActivation : "<<s.m_consolActivation<<endl<<"\tlogActivation : "<<s.m_logActivation;
    return os;
}

void Server::askValueAttribute(){
    cout<<endl<<"Souhaitez-vous ecrire les donnees dans la console ? (Oui ("<<YES<<") ou Non ("<<NO<<") > ";  // Définitions des modalités d'écriture de l'objet de classe
    m_consolActivation=yesNoAnswerControl(YES,NO);                          // Server, attribut de l'objet Scheduler

    cout<<endl<<"Souhaitez-vous ecrire les donnees dans les fichiers de log ? (Oui ("<<YES<<") ou Non ("<<NO<<") > ";
    m_logActivation=yesNoAnswerControl(YES,NO);
}

