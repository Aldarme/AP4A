/**
 * @author RENON Emilien
 * @file MaClasse.hpp
 * @date 20/09/2022
 * @brief La classe Server permettra de recevoir les données envoyées par le Scheduler et aussi d'écrire dans la console ou dans un fichier ces données.
 */

//
// Define guards
#ifndef SERVER_H
#define SERVER_H
#include <iostream>
#include <fstream>
#include "Sensor.hpp"
/**
 * @class Server
 * @brief La classe Server permettra de recevoir les données envoyées par le Scheduler et aussi d'écrire dans la console ou dans un fichier ces données.
 */
class Server
{      
public:
    // Definition de la forme canonique
    Server(){};
    Server(Server &s);
    ~Server(){};
    // ...

    /**
     * @brief Ecrire les données reçues dans la console
     * @return void
     * @param Demande un int 
     */ 
    void consoleWrite(Sensor &param_sensor);

    /**
     * @brief Ecrire les données reçues dans un fichier
     * @return void
     * @param Demande un int 
     */
    void fileWrite(Sensor &param_sensor);
    
    /**
     * @brief Création d'un opérateur << pour la sortie des paramètres d'un capteur
     * @return ostream&
     * @param Demande ostream&, const Sensor&
     */
    friend class Sensor;
};




#endif // SERVER_H