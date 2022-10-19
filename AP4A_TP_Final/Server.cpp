/**
 *@author Lola ROQUILLON 
 *@file Server.cpp
 *@date 28/09/2022
 *@brief Cette classe affiche les différentes données des capteurs dans la console puis les stockent dans leur fichier respectif
 */

#include "Server.hpp"
#include <iostream>
#include <fstream>

using namespace std;

void Server::fileWrite(Sac_struct sac)   //sauvegarde
{
    
    ofstream Ftemp("dTemperature.txt", ios::app);      //ouverture du fichier "dTemperature.txt"
    if(Ftemp)  //On teste si tout est OK
    {
        Ftemp << sac.s_temp <<endl;     //écrire dans le fichier
        Ftemp.close();                  //fermeture du fichier
    }
    else    //sinon message d'erreur
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }

    ofstream Fhum("dHumidity.txt", ios::app);      //ouverture du fichier "dHumidity.txt"
    if(Fhum)  
    {
        Fhum << sac.s_hum <<endl;
        Fhum.close();
    }
    else 
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }

    ofstream Fpress("dPression.txt", ios::app);   //ouverture du fichier "dPression.txt"
    if(Fpress)  
    {
        Fpress << sac.s_press <<endl;
        Fpress.close();
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }

    ofstream Flight("dLight.txt", ios::app);     //ouverture du fichier "dLight.txt"
    if(Flight)  
    {
        Flight << sac.s_light <<endl;
        Flight.close();
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }

}

void Server::consolWrite(Sac_struct sac)  //affichage des valeurs des capteurs dans la console
{
    cout<<"Temperature = " << sac.s_temp <<" *C" << endl << "Pression = " << sac.s_press <<" hPa" << endl << "Humidity = " << sac.s_hum <<" %" << endl << "Light = " << sac.s_light <<endl;
    cout<<endl;
}

