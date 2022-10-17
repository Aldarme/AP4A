/**
 * @author Arthur
 * @file Server.hpp
 * @date 03/10/22
 * @brief Déclaration de la classe Server
 */

//DEFINE_GUARDS
#pragma once
#ifndef SERVER_HPP
#define SERVER_HPP

#include "DataPacket.hpp"

/**
* @class Server
* @brief Déclaration de la classe Server
*/
class Server
{
public:
    DataPacket data;

    /** 
    * @brief Déclaration de la forme canonique de coplien
    * @return Rien
    * @param Ceux par défaut
    */
    Server(): data(){};
    Server(const Server& server): data(server.data){};
    ~Server(){};

    /** 
    * @brief Methode pour écrire les données des capteurs dans un fichier
    * @return Rien
    * @param Aucun
    */
    void fileWrite();

    /** 
    * @brief Methode pour écrire les données des capteurs dans la console
    * @return Rien
    * @param Aucun
    */
    void consolWrite();

    /** 
    * @brief Réinitialise le fichier où sont entrées les valeurs
    * @return Rien
    * @param Aucun
    */
    void resetFile();
};

#endif //SERVER.H