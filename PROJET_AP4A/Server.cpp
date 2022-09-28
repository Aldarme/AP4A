/**
 * @author RENON Emilien
 * @file Server.cpp
 * @date 20/09/2022
 * @brief La classe Server permettra de recevoir les données envoyées par le Scheduler et aussi d'écrire dans la console ou dans un fichier ces données.
 */

#include "Server.hpp"
using namespace std;



void Server::consoleWrite(Sensor &param_sensor1,Sensor &param_sensor2,Sensor &param_sensor3,Sensor &param_sensor4){
    cout<<param_sensor1;
    cout<<param_sensor2;
    cout<<param_sensor3;
    cout<<param_sensor4;
}

void Server::fileWrite(Sensor &param_sensor1,Sensor &param_sensor2,Sensor &param_sensor3,Sensor &param_sensor4){
    ofstream myFile("C:/Users/renon/.vscode/LABAP4A/PROJET_AP4A/data.csv", ios::app); //Déclaration du flux et ouverture du fichier
    if(myFile)
    {
        myFile <<param_sensor1;
        myFile <<param_sensor2;
        myFile <<param_sensor3;
        myFile <<param_sensor4<<endl;
        myFile.close();
    }else
    {
        cout<<"Erreur d'ouverture"<<endl;
    }
}