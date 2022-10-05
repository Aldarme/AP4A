/**
 * @author Augustin Athané
 * @file Server.cpp
 * @date 24/09/2022
 * @brief Le serveur récupère les données ordonnées envoyés par le scheduler. Une fois récupérer ses données sont stockés
 */

#include <iostream>
#include <cstdlib>
#include <thread>
#include <fstream>
#include "Server.hpp"
using namespace std;


//Constructeur par défault
Server::Server()
{
    //Par défault on mettera toutes les valeurs à 0
    valHumidity = 0;
    valLight = 0;
    valPression = 0;
    valTemperature = 0;
    simulation = false;
}

//Constructeur paramétré
Server::Server(int t, int h, int l, int p)
{
    valHumidity = h;
    valLight = l;
    valPression = p;
    valTemperature = t;
    simulation = false;
}

//Constructeur par recopie
Server::Server(const Server &other)
{
    valHumidity = other.valHumidity;
    valLight = other.valLight;
    valPression = other.valPression;
    valTemperature = other.valTemperature;
    simulation = other.simulation;
}

//Destructeur
Server::~Server(){}

//Méthodes

//Visualiser les données arrivantes dans la console
void Server::consoleWrite()
{
    //On écrit dans la console les données
    cout << "La température est de: "<< "\033[32m" << valTemperature << "\033[37m" << " °C" << endl;
    cout << "L'humiditée est de: "<< "\033[32m" << valHumidity << "\033[37m" << " %" << endl;
    cout << "La pression est de: "<< "\033[32m" << valPression << "\033[37m" << " hPasc" << endl;
    if(valLight){
        cout << "Light: " << "\033[33m" << "Lumineux" << endl;
        cout << "\033[37m";
    }else{
        cout << "Light: " << "\033[90m" << "Sombre" << endl;
        cout << "\033[37m";
    }
    cout << "\033[36m" << "----------------------------" << endl;
    cout << "\033[37m";
}

//Socker les donn ́ees des capteurs dans des fichiers de logs 
void Server::fileWrite()
{
    string const file("C:/Users/Augustin Athane/AP4A/Projet_AP4A/Server/Logs.csv");
    ofstream myFile_Handler;

    //fichier ouvert
    myFile_Handler.open(file, ios::app);

    if(myFile_Handler){
        myFile_Handler <<"Humidity: " << valHumidity << " %" << ";";
        myFile_Handler <<"Light: " << valLight << ";";
        myFile_Handler <<"Pression: " << valPression << " hPasc" << ";";
        myFile_Handler <<"Temperature: " << valTemperature << " C" << endl;
    }else{
        cout << "\033[31m" << "ERREUR: Imposible d'ouvrir le fichier log." <<endl;
        cout << "\033[37m";
    }
    myFile_Handler.close();
}

void Server::startSimulation(){
    simulation = true;
    while(simulation){
        this_thread::sleep_for(chrono::milliseconds(1000)); // Toutes le secondes on affiche les valeurs
        if(doPrintConsole){ //Si l'utilisateur a demander d'ecrire dans la console
            consoleWrite(); // On écrit les valeurs dans la console
        }
        if(doLog){ //si l'utilisateur a activer les logs
            fileWrite();            
        }

    }
}

void Server::endSimulation(){
    simulation = false;
}

//Recevoir des données des capteurs, On créer une fonction par capteur en vue du rendu final
void Server::updateTemp(int t){
    valTemperature = t;
}

void Server::updateHumidity(int h){
    valHumidity = h;
}

void Server::updateLight(int l){
    valLight = l;
}

void Server::updatePression(int p){
    valPression = p;
}

void Server::updateDoLog(bool doLog_){
    doLog = doLog_;
}

void Server::updateDoPrintConsole(bool doPrintConsole_){
    doPrintConsole = doPrintConsole_;
}