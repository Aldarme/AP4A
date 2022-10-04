/*
@author BENEDUCI Marie
@file  Server.cpp
@date 19/09/2022
@brief  Implementation de la Classe ayant pour objectif de recevoir les données des capteurs, les stocker dans un fichier de log (rendu intermediaire) et les afficher dans la console
*/


#include "../hpp/Server.hpp"
#include <fstream>
#include <string>
#include <iostream>

Server::Server(){
}

Server::~Server()
{
}

// Ouverture du fichier log pour l'ecriture des données ( 1 seul fichier pour le rendu intermédiaire)
std::string const nomFichier("../log/file.txt"); 
std::ofstream monFlux(nomFichier.c_str());

void Server::newStatement(int relevé_p){
    monFlux << "--------------Relevé n°"<< relevé_p <<"--------------" << std::endl; // affichage du numéro des relevé pour plus de lisibilité dans le fichier log
    std::cout << "--------------Relevé n°"<< relevé_p <<"--------------" << std::endl; // affichage du numéro des relevé pour plus de lisibilité dans le terminal
}

void Server::fileWrite(char nom_p[], int value_p, char unit_p[]){
    if(monFlux)    
    {
        monFlux << nom_p << " : " << value_p << " " << unit_p << std::endl; // ecriture des données dans le fichier log
        
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl; // Affichage d'une erreur dans le terminal dans le cas où il est impossible d'ouvrir le fichier log
    }

}

void Server::consolWrite(char nom_p[], int value_p, char unit_p[]){
    std::cout << nom_p << " : " << value_p << " " << unit_p << std::endl; // ecriture des données dans le terminal
}

void Server::fileAndConsoleWrite(char nom_p[], int value_p, char unit_p[]){ //Fonction public regroupant l'appel de la fonction d'affichage dans la console et celle du stockage dans le fichier log
    consolWrite(nom_p, value_p, unit_p);
    fileWrite(nom_p,value_p, unit_p);
}


