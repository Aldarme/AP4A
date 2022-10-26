/**
 * @author lois roger
 * @file Server.hpp
 * @date 05/10/2022
 * @brief écrit les différentes valeurs des capteurs dans leur fichier dédiée et dans la console
 */




#include <fstream>
using namespace std;
#include <string>
#include "Server.hpp"
#include <iostream>


void Server::filewrite(float valeurt, int valeurp, bool valeurl, float valeurh, string fichier) //fonction qui écrrit les données dans le fichier correspondant 
{
    if(fichier =="temperaturelog.txt")
    {
        ofstream templog;
        templog.open("temperaturelog.txt", ios ::app);
        templog<<"la température est de "<<valeurt<<" °C"<<endl;
        templog.close();
    }


    if(fichier =="humiditylog.txt")
    {
        ofstream humlog;
        humlog.open("humiditylog.txt", ios ::app);
        humlog<<"l'humidité est de "<<valeurh<<" %"<<endl;
        humlog.close();
    }
   
    if(fichier == "lightlog.txt")
    {
        ofstream lightlog;
        lightlog.open("lightlog.txt", ios ::app);
        lightlog<<"la lumière vaut "<<valeurl<<endl;
        lightlog.close();
    }
   
    if(fichier == "pressionlog.txt")
    {
        ofstream preslog;
        preslog.open("pressionlog.txt", ios ::app);
        preslog<<"la pression est de "<<valeurp<<" hPa"<<endl;
        preslog.close();
    }
    

}

void Server::consolwrite(float valeurt, int valeurp, bool valeurl, float valeurh, string capteur)
{
    if(capteur == "temperature")
    {
        std::cout<<"la temperature est de "<<valeurt<<" °C"<<endl;
    }
    if(capteur == "humidity")
    {
        std::cout<<"l'humidite est de "<<valeurh<<" %"<<endl;
    }
    if(capteur == "pression")
    {
        std::cout<<"la pression est de "<<valeurp<<" hPa"<<endl;
    }
    if(capteur == "light")
    {
        std::cout<<"la lumière vaut "<<valeurl<<endl;
    }
    
}





