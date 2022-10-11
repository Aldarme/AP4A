/**
 * @author Arthur
 * @file Server.cpp
 * @date 03/10/22
 * @brief Implémentation de la classe Server
 */

#include <iostream>
#include <fstream>
#include "Server.hpp"
#include "DataPacket.hpp"

using namespace std;

void Server::fileWrite()
{
    ofstream logFile("logFile.txt", ios::app);
    
    if (logFile)
    {
        logFile << "-T;" << data.temperature <<
                ";H;" << data.humidity <<
                ";P;" << data.pressure <<
                ";L;" << data.light << endl;

        logFile.close();
    }

    else cout << "Impossible d'ouvrir le fichier" << endl;

};

void Server::consolWrite()
{
    cout << "| T- " << data.temperature <<
            ", H- " << data.humidity <<
            ", P- " << data.pressure <<
            ", L- " << data.light << endl;
};

void Server::resetFile()
{
    ofstream logFile("logFile.txt", ios::trunc);
}
