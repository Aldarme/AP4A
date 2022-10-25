/**
 * @author Arthur
 * @file Server.hpp
 * @date 03/10/22
 * @brief Déclaration de la classe Server
 */

//DEFINE_GUARDS
#ifndef SERVER_HPP
#define SERVER_HPP

#include <thread>
#include <iostream>
#include <fstream>

#include "DataPacket.hpp"

/**
* @class Server
* @brief Déclaration de la classe Server
*/
class Server
{
public:
    DataPacket donnee;

    /** 
    * @brief Déclaration de la forme canonique de coplien
    * @return Rien
    * @param Ceux par défaut
    */
    Server(): donnee(){};
    Server(const Server& server): donnee(server.donnee){};
    ~Server(){};

    /** 
    * @brief Methode pour écrire les données des capteurs dans un fichier
    * @return Rien
    * @param Entier temps
    */
    void fileWrite(int time);

    /** 
    * @brief Methode pour écrire les données des capteurs dans la console
    * @return Rien
    * @param Entier temps
    */
    void consolWrite(int time);

    /** 
    * @brief Réinitialise le fichier où sont entrées les valeurs
    * @return Rien
    * @param Aucun
    */
    void resetFile();
};

#endif //SERVER.H