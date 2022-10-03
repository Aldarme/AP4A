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


void Server::fileWrite(char nom[], int value){
    if(monFlux)    
    {
        monFlux << nom << " : " << value << std::endl;
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
    
}

void Server::consolWrite(char nom[], int value, char unit[5]){
    std::cout << nom << " : " << value << " " << unit << std::endl;
}

void Server::fileAndConsoleWrite(char nom[], int value, char unit[5]){
    consolWrite(nom, value, unit);
    fileWrite(nom,value);
}


