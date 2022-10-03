#include "../hpp/Server.hpp"
#include <fstream>
#include <string>
#include <iostream>

Server::Server(){
}

Server::~Server()
{
}

std::string const nomFichier("../log/file.txt");
std::ofstream monFlux(nomFichier.c_str());

void Server::newStatement(int relevé){
    monFlux << "--------------Relevé n°"<< relevé <<"--------------" << std::endl;
    std::cout << "--------------Relevé n°"<< relevé <<"--------------" << std::endl;
}

void Server::fileWrite(char nom[], int value, char unit[]){
    if(monFlux)    
    {
        monFlux << nom << " : " << value << " " << unit << std::endl;
        
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }

}

void Server::consolWrite(char nom[], int value, char unit[]){
    std::cout << nom << " : " << value << " " << unit << std::endl;
}

void Server::fileAndConsoleWrite(char nom[], int value, char unit[]){
    consolWrite(nom, value, unit);
    fileWrite(nom,value, unit);
}


