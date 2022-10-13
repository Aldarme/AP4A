/**
 * @author Augustin Athané
 * @file Server.cpp
 * @date 24/09/2022
 * @brief Le serveur récupère les données ordonnées envoyés par le scheduler.  Une fois récupérer ses données sont stockés ou/et affichés dans la console
 */

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <chrono>
using namespace std::chrono;
#include <thread>
#include <ctime>
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
Server::Server(float t, float h, bool l, int p)
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
    cout << "La temperature est de: " << valTemperature << " C" << endl;
    cout << "L'humiditee est de: " << valHumidity << " %" << endl;
    cout << "La pression est de: " << valPression << " hPasc" << endl;
    if(valLight){
        cout << "Light: Lumineux" << endl;
    }else{
        cout << "Light: Sombre" << endl;
    }
    cout << "----------------------------" << endl;
}

//Socker les donn ́ees des capteurs dans des fichiers de logs 
void Server::fileWrite()
{
    string const file("C:/Users/Augustin Athane/AP4A/Projet_AP4A/Server/Logs.csv"); // On écrit dans un fichier csv, permet une meilleur lecture
    ofstream myFile_Handler;

    //fichier ouvert
    myFile_Handler.open(file, ios::app);

    if(myFile_Handler){
        myFile_Handler <<"Humidity: " << valHumidity << " %" << ";"; // ";" signifie qu'on change de colonne 
        myFile_Handler <<"Light: " << valLight << ";";
        myFile_Handler <<"Pression: " << valPression << " hPasc" << ";";
        myFile_Handler <<"Temperature: " << valTemperature << " C" << endl;
    }else{
        cout << "ERREUR: Imposible d'ouvrir le fichier log." <<endl;
    }
    myFile_Handler.close();
}

void Server::startSimulation(){ // Simulation
    // Le seveur tourne de lui même que le scheduler lui envoie des valeurs ou non. Il affiche et écrit dans le log toutes les secondes
    simulation = true;
    while(simulation){ // simulation passe à false lorsque endSimulation est appelé
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
void Server::updateTemp(float t){
    valTemperature = t;
}

void Server::updateHumidity(float h){
    valHumidity = h;
}

void Server::updateLight(bool l){
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