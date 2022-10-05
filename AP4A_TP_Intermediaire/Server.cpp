/**
 *@author Lola ROQUILLON 
 *@file Server.cpp
 *@date 28/09/2022
 *@brief Cette classe affiche les différentes donNées des capteurs dans la console puis les stockent dans leur fichier respectif
 */

#include <iostream>
#include "Server.hpp"
#include <fstream>
using namespace std;

Server::Server()
{
    //initialisation des valeurs des capteurs
    m_temp=0;
    m_hum=0;
    m_light=0;
    m_press=0;
}

void Server::mesDonnee(int temp_p, int hum_p, int press_p, int light_p)
{
    m_temp=temp_p;
    m_hum=hum_p;
    m_press=press_p;
    m_light=light_p;
}

Server::~Server	(){}


void Server::fileWrite() //sauvegarde
{
    ofstream Ftemp(".\\dTemperature.txt", ios::app);    //ouverture du fichier "dTemperature.txt"
    if(Ftemp)   //On teste si tout est OK
    {
        Ftemp << m_temp <<endl; //ajout de la valeur de la température à la fin du fichier
    }
    else        //sinon message d'erreur
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }

    ofstream Fhum(".\\dHumidity.txt", ios::app);      //ouverture du fichier "dHumidity.txt"
    if(Fhum)  
    {
        Fhum << m_hum <<endl;
    }
    else 
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }

    ofstream Fpress(".\\dPression.txt", ios::app);   //ouverture du fichier "dPression.txt"
    if(Fpress)  //On teste si tout est OK
    {
        Fpress << m_press <<endl;
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }

    ofstream Flight(".\\dLight.txt", ios::app);     //ouverture du fichier "dLight.txt"
    if(Flight)  //On teste si tout est OK
    {
        Flight << m_light <<endl;
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }

}

void Server::consolWrite()  //affichage des valeurs des capteurs dans la console
{
    cout<<"Temperature = " << m_temp <<"*C" << endl << "Pression = " << m_press <<"hPa" << endl << "Humidity = " << m_hum <<"%" << endl << "Light = " << m_light <<endl;
    cout<<"Si vous souhaitez arreter la simulation faite un controle c"<<endl <<endl;
}

