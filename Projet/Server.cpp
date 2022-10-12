/**
 * @author Erhart Eliott
 * @file Server.cpp
 * @date 03/10/2022
 * @brief 
 */

#include "Server.hpp"
using namespace std;

void Server::consoleWrite(int tps)
{
        cout << "Humidity: " << H << " g/m^3\n" << endl;
        cout << "Light: " << L << "\n" << endl;
        cout << "Pressure: " << P << " KPa\n" << endl;
        cout << "Temperature: " << T <<" °C \n" << endl;
}

void Server::fileWrite(int tps)
{
        ofstream monFlux("Data.txt",ios::app);
        if(monFlux)    
        {
                monFlux << "SENSOR DATA (à "<< tps << " secondes du début)\n" << endl;
                monFlux << "Humidity: " << H << " g/m^3\n" << endl;
                monFlux << "Light: " << L << " \n" << endl;
                monFlux << "Pressure: " << P << " KPa\n" << endl;
                monFlux << "Temperature: " << T <<" °C \n\n" << endl;
        }
        else
        {
                cerr << "ERREUR: Impossible d'ouvrir le fichier." << endl;
        }
}

void Server::fileClear()
{
        ofstream monFlux("Data.txt");
}
