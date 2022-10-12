/**
 * @author lois roger
 * @file Server.hpp
 * @date 05/10/2022
 * @brief écrit les différentes valeurs des capteurs dans leur fichier dédiée et dans la console
 */


#ifndef SERVER_H
#define SERVER_H
#include <fstream>
using namespace std;
#include <string>
#include "Server.hpp"
#include <iostream>


void Server::filewrite(int valeurt, int valeurp, int valeurl, int valeurh)
{
    ofstream templog;
    templog.open("temperaturelog.txt", ios ::app);
    templog<<"la température vaut "<<valeurt<<" °C"<<endl;
    templog.close();


    ofstream humlog;
    humlog.open("humiditylog.txt", ios ::app);
    humlog<<"l'humidité vaut "<<valeurh<<" %"<<endl;
    humlog.close();
   
    ofstream lightlog;
    lightlog.open("lightlog.txt", ios ::app);
    lightlog<<"la lumière vaut "<<valeurl<<endl;
    lightlog.close();
   
    ofstream preslog;
    preslog.open("pressionlog.txt", ios ::app);
    preslog<<"la pression vaut "<<valeurp<<" hPa"<<endl;
    preslog.close();
    

}

void Server::consolwrite(int valeurt, int valeurh, int valeurl, int valeurp)
{
    std::cout<<valeurt<<endl;
    std::cout<<valeurh<<endl;
    std::cout<<valeurl<<endl;
    std::cout<<valeurp<<endl;
}



#endif