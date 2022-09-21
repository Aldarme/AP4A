/**
 * @author RENON Emilien
 * @file Server.cpp
 * @date 20/09/2022
 * @brief La classe Server permettra de recevoir les données envoyées par le Scheduler et aussi d'écrire dans la console ou dans un fichier ces données.
 */

#include "Server.hpp"
using namespace std;
void Server::consoleWrite(int i){
    cout<<i<<endl;
}

void Server::fileWrite(int i){
    ofstream myFile("data.txt", ios::out | ios::trunc); //Déclaration du flux et ouverture du fichier
    if(myFile)
    {
        myFile <<i<<endl;
        myFile.close();
    }else
    {
        cout<<"Erreur d'ouverture"<<endl;
    }
}