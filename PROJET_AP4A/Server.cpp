/**
 * @author RENON Emilien
 * @file Server.cpp
 * @date 20/09/2022
 * @brief La classe Server permettra de recevoir les données envoyées par le Scheduler et aussi d'écrire dans la console ou dans un fichier ces données.
 */

#include "Server.hpp"
using namespace std;



void Server::consoleWrite(Sensor &param_sensor){
    cout<<param_sensor;
}

void Server::fileWrite(Sensor &param_sensor){
    ofstream myFile("C:/Users/renon/.vscode/LABAP4A/PROJET_AP4A/data.txt", ios::app); //Déclaration du flux et ouverture du fichier
    if(myFile)
    {
        myFile <<param_sensor<<endl;
        myFile.close();
    }else
    {
        cout<<"Erreur d'ouverture"<<endl;
    }
}