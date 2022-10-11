/**
* @author SZATKOWSKI Maxime
* @file Server.hpp
* @date 15/09/2022
* @brief fichier source contenant l'implémentation des méthodes de la classe Server
*/

#include "Server.hpp"

using namespace std;

using std::fstream;

Server::Server(){}

Server::Server(const Server& s) 
{
    consoleActivation = s.consoleActivation;
    logActivation = s.logActivation;
}

Server& Server::operator=(const Server& s) 
{
    consoleActivation = s.consoleActivation;
    logActivation = s.logActivation;
 
    return *this;
}

void Server::consoleWrite(const Packet param_p) 
{
    cout << "Luminosity  : " << param_p.m_light << " lumen" << endl;
    cout << "Pressure    : " << param_p.m_press << " hPa" << endl;
    cout << "Temperature : " << param_p.m_temp << " c" << endl;
    cout << "Humidity    : " << param_p.m_humid << " %" << endl;
}

//penser à mettre fpath en paramètre / demander le path le main (string)
void Server::fileWrite(const string fpath, const Packet param_p)
{
    ofstream file(fpath, ios::app);

    if (file)
    {  
        file << " Luminosity  : " << param_p.m_light << " lumen" << endl;
        file << " Pressure    : " << param_p.m_press << " hPa" << endl;
        file << " Temperature : " << param_p.m_temp << " c" << endl;
        file << " Humidity    : " << param_p.m_humid << " %" << endl;
        
        file.close();
    }
    else
    {
        cerr << "Cannot open file" << endl;
    }
}

Server& Server::setConsole()
{
    char c;
    bool b;
    cout << "Voulez vous ecrire dans la console (O/N)" << endl;
    cin >> c;
    if (c == 'O') {
        b = true;
    }
    else {
        b = false;
    }
    consoleActivation = b;

    return*this;

}

Server& Server::setLogActivation()
{
    char c;
    bool b;
    cout << "Voulez vous ecrire dans le fichier log (O/N)" << endl;
    cin >> c;
    if (c == 'O') {
        b = true;
    }
    else {
        b = false;
    }
    logActivation = b;

    return*this;

}

bool Server::getConsoleActiv() 
{
    return consoleActivation;
}

bool Server::getLogActiv()
{
    return logActivation;
}