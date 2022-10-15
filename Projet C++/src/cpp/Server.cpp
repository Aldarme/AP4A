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
#include <cstring>



Server::Server(){
}

Server::~Server()
{
}

// Ouverture du fichier log pour l'ecriture des données ( 1 seul fichier pour le rendu intermédiaire)
// std::string const nomFichier("../log/file.txt"); 
// std::ofstream monFlux(nomFichier.c_str());

// void Server::openFile(char nom_p[]){
//     // std::string const nomFichier("../log/file.txt"); 
//     std::string nomFichier("../log/");
//     std::string nomF = nom_p;
//     std::string extensionF(".txt");

//     nomFichier += nomF;
//     nomFichier += extensionF;


//     int n = nomFichier.length();

//     char char_nomFichier[n + 1];
 
//     // copying the contents of the
//     // string to char array
//     strcpy(char_nomFichier, nomFichier.c_str());

//     // std::ofstream monFlux(nomFichier.c_str()); 
//     std::ofstream monFlux(nomFichier, std::ios::app);

//     if(monFlux)    
//     {
//         monFlux << nom_p << " : " << "1" << std::endl; // ecriture des données dans le fichier log
//             }
//     else
//     {
//         std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl; // Affichage d'une erreur dans le terminal dans le cas où il est impossible d'ouvrir le fichier log
//     }


//     // FILE *ecr = fopen(char_nomFichier,"wt");
//     // if (ecr)
//     //     {
//     //     char MaLigne[8] = "test1";
//     //     char MaLigne2[10] = "test2";
//     //     fprintf(ecr,"%s\n",MaLigne);
//     //     fprintf(ecr,"%s\n",MaLigne2);
//     //     fclose(ecr);
//     //     }
// }



// pas utilisé pour le rendu final
void Server::newStatement(int relevé_p){    
    std::cout << "--------------Relevé n°"<< relevé_p <<"--------------" << std::endl; // affichage du numéro des relevé pour plus de lisibilité dans le terminal
}

template<typename T>
void Server::fileWrite(char nom_p[], T value_p, char unit_p[], int relevé_p){
    
    std::string nomFichier("../log/");
    std::string nomF = nom_p;
    std::string extensionF(".txt");

    nomFichier += nomF;
    nomFichier += extensionF;

    std::ofstream monFlux(nomFichier, std::ios::app);

    if(monFlux)    
    {
        monFlux << "--------------Relevé n°"<< relevé_p <<"--------------" << std::endl; // affichage du numéro des relevé pour plus de lisibilité dans le fichier log
        monFlux << nom_p << " : " << value_p << " " << unit_p << std::endl; // ecriture des données dans le fichier log
            }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl; // Affichage d'une erreur dans le terminal dans le cas où il est impossible d'ouvrir le fichier log
    }
    
    

}

template<typename T>
void Server::consolWrite(char nom_p[], T value_p, char unit_p[]){
    std::cout << nom_p << " : " << value_p << " " << unit_p << std::endl; // ecriture des données dans le terminal
}

template<typename T>
void Server::fileAndConsoleWrite(char nom_p[], T value_p, char unit_p[], int relevé_p){ //Fonction public regroupant l'appel de la fonction d'affichage dans la console et celle du stockage dans le fichier log
    consolWrite(nom_p, value_p, unit_p);
    fileWrite(nom_p,value_p, unit_p, relevé_p);
}


