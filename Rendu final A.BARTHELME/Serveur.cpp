/**
 * @author A.BARTHELME
 * @file serveur.cpp
 * @date 12/10/2022
 * @brief Fichier du serveur, gère l'écriture dans le fichier et l'affichage dans la console
 * @version Finale 
 * @details voir dans le fichier serveur.hpp pour plus d'informations
**/ 

#include<iostream>
#include<string>
#include<fstream>
#include<ctime>
#include "Serveur.hpp"
#include "Paquet.hpp"
#include <chrono>

using namespace std;

Serveur::Serveur()
{
    m_nom = "Inconnu";
}
Serveur::Serveur(string nom)
{
    m_nom = nom;
}

//ancien code :

/*void Serveur::fileWriter(Paquet paquet){
    string data = paquet.data();
    string unite = paquet.Getunit();

if (unite == "%")
{
    string const fichierH("logHum.txt");
    ofstream logH(fichierH.c_str(),ios::app);
    if(logH){
        //afficher l'heure et la date
        time_t now = time(0);
        char* dt = ctime(&now);
        logH << dt << " : " <<endl;
        logH << data << endl;
        logH << endl;
    }
    else{
        cout << "Impossible d'ouvrir le fichier !" << endl;
    }
}
else if (unite == "Lux")
{
    string const fichierL("logLum.txt");
    ofstream logL(fichierL.c_str(),ios::app);
    if(logL){
        time_t now = time(0);
        char* dt = ctime(&now);
        logL << dt <<" : " << endl;
        logL << data << endl;
        logL << endl;
    }
    else{
        cout << "Impossible d'ouvrir le fichier !" << endl;
    }
}
else if (unite == "hPa"){
    string const fichierP("logPress.txt");
    ofstream logP(fichierP.c_str(),ios::app);
    if(logP){
        time_t now = time(0);
        char* dt = ctime(&now);
        logP << dt <<" : " <<  endl;
        logP << data << endl;
        logP << endl;
    }
    else{
        cout << "Impossible d'ouvrir le fichier !" << endl;
    }
}
else if (unite == "Celsius"){
        string const fichier("logTem.txt");
        ofstream log(fichier.c_str(),ios::app);
        if(log){
            time_t now = time(0);
            char* dt = ctime(&now);
            log << dt << " : " << endl;
            log << data << endl;
            log << endl;
        }
        else{
            cout << "Impossible d'ouvrir le fichier !" << endl;
        }
}

else{
    cout << "Unite non reconnue" << endl;
}
}*/

/*void Serveur::consoleWriter(Paquet paquet){
    string data = paquet.data();
    time_t now = time(0);
    char* dt = ctime(&now);
    cout << dt << endl;
    cout << data << endl;
    cout << endl;
}

void Serveur::CleanFile(){
    string const fichier("log.txt");
    ofstream log(fichier.c_str(),ios::trunc);
    if(log){
        log << " " << endl;
    }
    else{
        cout << "Impossible d'ouvrir le fichier !" << endl;
    
    }
}*/

Serveur::~Serveur()
{
}