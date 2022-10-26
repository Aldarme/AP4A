/**
 * @author Planchin Arnaud
 * @file Server.hpp
 * @date 03/10/2022
 * @brief Définition de la classe Server qui reçoit un paquet, affiche ou non dans la console et/ou écrit ou non dans un fichier les données du paquet
 */

#ifndef SERVER_H
#define SERVER_H

#include "Paquet.hpp"

class Server
{
    
    friend class Scheduler;
    
private:

    // Attributs d'un Server
    Paquet server_Pack;
    char choix_affichage;
    char choix_ecriture;

public:

    /**
     * @brief Forme Canonique de Coplien de la classe Server
     */
    virtual ~Server(){}
    Server():server_Pack(){}
    Server(const Server& server):server_Pack(server.server_Pack){} 

    /**
     * @brief Demande à l'utilisateur si il veut écrire dans les fichiers ou non et/ou afficher dans la console ou non
     * @return Un server avec les variables changées
     */
    Server choix_Log();
    
    /**
     * @brief Efface les données précedemment écrite dans les fichiers si il y a écriture dans les fichiers
     */
    void fileRaZ();

    /**
     * @brief Ecrit les valeurs de chaque capteur dans leurs fichiers texte dédiés si il y a écriture dans les fichiers
     * @param temps - temps en seconde
     */
    void fileWrite(int temps);

    /**
     * @brief Ecrit dans la console les valeur prise par chaque capteur en fonction du temps si il y a affichage dans la console
     * @param temps - temps en seconde
     */
    void consolWrite(int temps);

};

#endif // SERVER_H