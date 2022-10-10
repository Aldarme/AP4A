/**
 * @author RENON Emilien
 * @file Server.cpp
 * @date 20/09/2022
 * @brief La classe Server permettra de recevoir les données envoyées par le Scheduler et aussi d'écrire dans la console ou dans un fichier ces données.
 */

#include "Server.hpp"
using namespace std;

template <class T>
void Server::consoleWrite(const Sensor<T> &param_sensor1){
    cout<<param_sensor1;
}

template <class T>
void Server::fileWrite(const Sensor<T> &param_sensor1){
    ofstream myFile("C:/Users/renon/.vscode/LABAP4A/PROJET_AP4A/data.csv", ios::app); //Déclaration du flux et ouverture du fichier
    if(myFile)
    {
        myFile << param_sensor1;
        myFile.close();
    }else
    {
        cout<<"Erreur d'ouverture"<<endl;
    }
}