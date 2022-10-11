/**
 * @author Planchin Arnaud
 * @file Server.hpp
 * @date 03/10/2022
 * @brief Définition de la classe Server qui reçoit un paquet, affiche dans la console et écrit dans un fichier les données du paquet
 */

#ifndef SERVER_H
#define SERVER_H

#include "Paquet.hpp"
#include <iostream>
#include <fstream>
using namespace std;

class Server
{
public:

    Paquet server_Pack;

    /**
     * @brief Forme Canonique de Coplien de la classe Server
     */
    ~Server(){}
    Server():server_Pack(){}
    Server(const Server& server):server_Pack(server.server_Pack){}

    void fileRaZ();

    /**
     * @brief écrire dans le fichier texte les valeurs de chaque capteur
     * @return Rien
     * @param temps - temps en seconde
     */
    void fileWrite(int temps);

    /**
     * @brief écrire dans la console la valeur prise
     * @return Rien 
     * @param temps - temps en seconde
     */
    void consolWrite(int temps);

};

#endif // SERVER_H