/*
@author BENEDUCI Marie
@file  Server.hpp
@date 19/09/2022
@brief  Déclaration de la Classe ayant pour objectif de recevoir les données des capteurs, les stocker dans un fichier de log (rendu intermediaire) et les afficher dans la console
*/

#include <string>


#ifndef SERVER_HPP
#define SERVER_HPP

class Server
{
private:
    void fileWrite(char nom_p[], std::string value_p, char unit_p[], int relevé_p) ; // fonction d'écriture des données reçues pour chaques capteurs dans un fichier log (pour le rendu intermédiaire)
    void consolWrite(char nom_p[], std::string value_p, char unit_p[]); // fonction d'écriture des données reçues pour chaques capteurs dans le terminal

public:
    Server(); // Constructeur par défaut
    ~Server(); // Destructeur
    Server (const Server&); // Constructeur de recopie
    Server &operator=(const Server&); // Opérateur d'affectation
    void newStatement(int relevé_p); // fonction d'affichage du numéro de relevé des données des Sensors.
    void fileAndConsoleWrite(char nom_p[], std::string value_p, char unit_p[], int relevé_p); // Fonction regroupant l'affichage dans la console et le stockage dans le fichier log
    // void openFile(char nom_p[]);

};

#endif