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

void Server::newStatement(int relevé){
    monFlux << "--------------Relevé n°"<< relevé <<"--------------" << std::endl; // affichage du numéro des relevé pour plus de lisibilité dans le fichier log
    std::cout << "--------------Relevé n°"<< relevé <<"--------------" << std::endl; // affichage du numéro des relevé pour plus de lisibilité dans le terminal
}

void Server::fileWrite(char nom[], int value, char unit[]){
    if(monFlux)    
    {
        monFlux << nom << " : " << value << " " << unit << std::endl; // ecriture des données dans le fichier log
        
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl; // Affichage d'une erreur dans le terminal dans le cas où il est impossible d'ouvrir le fichier log
    }

}

void Server::consolWrite(char nom[], int value, char unit[]){
    std::cout << nom << " : " << value << " " << unit << std::endl; // ecriture des données dans le terminal
}

void Server::fileAndConsoleWrite(char nom[], int value, char unit[]){ //Fonction public regroupant l'appel de la fonction d'affichage dans la console et celle du stockage dans le fichier log
    consolWrite(nom, value, unit);
    fileWrite(nom,value, unit);
}


