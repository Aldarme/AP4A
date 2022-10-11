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
#include "Temperature.hpp"
#include "Pression.hpp"
#include "Humidity.hpp"
#include "Light.hpp"
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
    void consoleWrite(const Sensor<T> &param_sensor);


    /**
     * @brief Ecrire les données reçues dans un fichier
     * @return void
     * @param  Temperature 
     */
    template <class T>
    void fileWrite(const Temperature<T> &param_sensor);

    /**
     * @brief Ecrire les données reçues dans un fichier
     * @return void
     * @param Humidity 
     */
    template <class T>
    void fileWrite(const Humidity<T> &param_sensor);

    /**
     * @brief Ecrire les données reçues dans un fichier
     * @return void
     * @param Pression
     */
    template <class T>
    void fileWrite(const Pression<T> &param_sensor);

    /**
     * @brief Ecrire les données reçues dans un fichier
     * @return void
     * @param Light
     */
    template <class T>
    void fileWrite(const Light<T> &param_sensor);
    
    template <class T> friend class Sensor;
    template <class T> friend class Temperature;
    template <class T> friend class Humidity;
    template <class T> friend class Pression;
    template <class T> friend class Light;
};




#endif // SERVER_H