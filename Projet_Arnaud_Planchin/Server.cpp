/**
 * @author Planchin Arnaud
 * @file Server.cpp
 * @date 03/10/2022
 * @brief Définition de chaque méthode de Server
 */

#include "Server.hpp"

void Server::fileRaZ(){

    ofstream mon_fichier("Capteurs.txt");
    
    mon_fichier.close();

}  

void Server::fileWrite(int temps)
{
    ofstream mon_fichier("Capteurs.txt", ios::app);  
    
    mon_fichier << "Temps : " << temps << " s,\n"
                << "Température : " << server_Pack.temperature.data << " °C,\n"
                << "Pression : " << server_Pack.pression.data << " kPa,\n" 
                << "Humidité : " << server_Pack.humidite.data << " g/m^3,\n" 
                << "Luminosité : " << server_Pack.lumiere.data << endl << endl;

    mon_fichier.close();
}

void Server::consolWrite(int temps)
{
    cout    << "Temps : " << temps << " s,\n"
            << "Température : " << server_Pack.temperature.data << " °C,\n"
            << "Pression : " << server_Pack.pression.data << " kPa,\n" 
            << "Humidité : " << server_Pack.humidite.data << " g/m^3,\n" 
            << "Luminosité : " << server_Pack.lumiere.data << endl << endl;
}