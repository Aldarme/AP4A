#include "../hpp/Server.hpp"
#include <fstream>
#include <string>
#include <iostream>

// Server::Server(){
// }

// Server::~Server()
// {
// }

std::string const nomFichier("../log/file.txt");
std::ofstream monFlux(nomFichier.c_str());


void Server::fileWrite(char nom, int value){
    if(monFlux)    
    {
        monFlux <<" Valeur" << nom << ":" << value << std::endl;
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
    
}

void Server::consolWrite(char nom, int value){
    std::cout <<" Valeur " << nom << ":" << value << std::endl;
}

void Server::fileAndConsoleWrite(char nom, int value){
    consolWrite(nom, value);
    fileWrite(nom,value);
}


