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

void Server::fileWrite(const string& nomFichier, float data)
{

    ofstream FichierStockage(nomFichier.c_str(), ios::app);  // Ouverture du fichier

    if(FichierStockage)
    {
        FichierStockage << data<<endl;                       // On écrit la donnée dans le fichier s'il n'y a pas d'erreur à l'ouverture
    }
    else
    {
        cout << "ERREUR : Ouverture du fichier impossible." << endl;   // Sinon, on n'écrit pas la donnée, et on averti l'utilisateur qu'il y a eu une erreur
    }

}

void Server::consoleWrite(const std::string& dataUnit, float data)
{
    cout << data<<" "<<dataUnit<<"\t\t";         // On écrit dans la console la donnée suivie de son unité donnée
}
