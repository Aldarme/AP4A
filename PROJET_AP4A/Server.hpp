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
     * @param 4 sensors
     */ 
    template <class T>
    void consoleWrite(const Sensor<T> &param_sensor1);

    /**
     * @brief Ecrire les données reçues dans un fichier
     * @return void
     * @param 4 sensors 
     */
    template <class T>
    void fileWrite(const Sensor<T> &param_sensor1);
    
    template <class T> friend class Sensor;
};




#endif // SERVER_H