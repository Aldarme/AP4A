/**
 * @author RENON_Emilien
 * @file Server.cpp
 * @date 20/09/2022
 * @brief La classe Server permettra de recevoir les données envoyées par le Scheduler et aussi d'écrire dans la console ou dans un fichier ces données.
 */

#include "Server.hpp"
using namespace std;

template <class T>
void Server::consoleWrite(const Sensor<T> &param_sensor)
{
    cout<<param_sensor;
}

template <class T>
void Server::fileWrite(const Temperature<T> &param_sensor)
{
    ofstream myFile("C:/Users/renon/.vscode/LABAP4A/PROJET_AP4A/data_temperature.csv", ios::app); //Déclaration du flux et ouverture du fichier
    if(myFile)
    {
        myFile << param_sensor <<endl;
        myFile.close();
    }else
    {
        cout<<"Erreur d'ouverture"<<endl;
    }
}

template <class T>
void Server::fileWrite(const Pression<T> &param_sensor)
{
    ofstream myFile("C:/Users/renon/.vscode/LABAP4A/PROJET_AP4A/data_pression.csv", ios::app); //Déclaration du flux et ouverture du fichier
    if(myFile)
    {
        myFile << param_sensor <<endl;
        myFile.close();
    }else
    {
        cout<<"Erreur d'ouverture"<<endl;
    }
}

template <class T>
void Server::fileWrite(const Humidity<T> &param_sensor)
{
    ofstream myFile("C:/Users/renon/.vscode/LABAP4A/PROJET_AP4A/data_humidity.csv", ios::app); //Déclaration du flux et ouverture du fichier
    if(myFile)
    {
        myFile << param_sensor <<endl;
        myFile.close();
    }else
    {
        cout<<"Erreur d'ouverture"<<endl;
    }
}

template <class T>
void Server::fileWrite(const Light<T> &param_sensor)
{
    ofstream myFile("C:/Users/renon/.vscode/LABAP4A/PROJET_AP4A/data_light.csv", ios::app); //Déclaration du flux et ouverture du fichier
    if(myFile)
    {
        myFile << param_sensor <<endl;
        myFile.close();
    }else
    {
        cout<<"Erreur d'ouverture"<<endl;
    }
}