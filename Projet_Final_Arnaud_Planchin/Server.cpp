/**
 * @author Planchin Arnaud
 * @file Server.cpp
 * @date 03/10/2022
 * @brief Définition des méthodes de la classe Server
 */

#include "Server.hpp"
#include <iostream>
#include <fstream>
using namespace std;

Server Server::choix_Log()
{
    while(choix_affichage != 'O' && choix_affichage != 'N'){
        cout << "Voulez-vous afficher sur la console ? (O/N)"<< endl;
        cin >> choix_affichage;
    }
    
    while(choix_ecriture != 'O' && choix_ecriture != 'N'){
        cout << "Voulez-vous enregistrer les logs dans les fichiers ?(O/N)" << endl;
        cin >> choix_ecriture;
    }
    
    return *this;
}


void Server::fileRaZ()
{
    if(choix_ecriture == 'O') {
        ofstream fichier_Temp("Temperature.txt");  
        fichier_Temp.close();

        ofstream fichier_Pres("Pression.txt"); 
        fichier_Pres.close();

        ofstream fichier_Hum("Humidite.txt");
        fichier_Hum.close();

        ofstream fichier_Lum("Lumiere.txt");  
        fichier_Lum.close();
    }
}  


void Server::fileWrite(int temps)
{
    if(choix_ecriture == 'O'){
        ofstream fichier_Temp("Temperature.txt", ios::app);  
        fichier_Temp << "Temps : " << temps << " s, Température : " << server_Pack.temperature.data << " °C,\n";
        fichier_Temp.close();


        ofstream fichier_Pres("Pression.txt", ios::app);  
        fichier_Pres << "Temps : " << temps << " s, Pression : " << server_Pack.pression.data << " kPa,\n";
        fichier_Pres.close();


        ofstream fichier_Hum("Humidite.txt", ios::app);  
        fichier_Hum << "Temps : " << temps << " s, Humidité : " << server_Pack.humidite.data << " g/m^3,\n";
        fichier_Hum.close();


        ofstream fichier_Lum("Lumiere.txt", ios::app);  
        if (server_Pack.lumiere.data){ 
            fichier_Lum << "Temps : " << temps << " s, Lumière : allumé \n" ;
        } else {
            fichier_Lum << "Temps : " << temps << " s, Lumière : éteint \n" ;
        }
        fichier_Lum.close();
    }
}


void Server::consolWrite(int temps)
{
    if(choix_affichage == 'O'){
        cout    << "Temps : " << temps << " s,\n"
            << "Temperature : " << server_Pack.temperature.data << " degC,\n"
            << "Pression : " << server_Pack.pression.data << " kPa,\n" 
            << "Humidite : " << server_Pack.humidite.data << " g/m^3,\n";
        if (server_Pack.lumiere.data){ 
            cout << "Lumiere : allume. \n" ;
        } else {
            cout << "Lumiere : eteint. \n" << endl << endl;
        }
    }    
}