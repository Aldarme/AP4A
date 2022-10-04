/**
 * @author RENON Emilien
 * @file Scheduler.hpp
 * @date 23/09/2022
 * @brief Récupérer les données et les envoyer au serveur
 */

//
// Define guards
#ifndef SCHEDULER_H
#define SCHEDULER_H
#include <iostream>
#include <thread>
#include <chrono>
#include "Server.cpp"
#include "Sensor.cpp"
#include "Temperature.cpp"
#include "Pression.cpp"
#include "Humidity.cpp"
#include "Light.cpp"

/**
 * @class Scheduler
 * @brief La classe Scheduler permettra de créer les périodes de temps
 */
class Scheduler
{
public:
    // Definition de la forme canonique
    Scheduler();
    Scheduler(Server &param_server,Temperature &param_temperature,Humidity &param_humidity,Light &param_light,Pression &param_pression,int param_time);
    Scheduler(Scheduler &s);
    ~Scheduler(){};
    // ...

    /**
     * @brief Fonction qui récupère les données des capteurs et envoi les valeurs des capteurs au serveur en utilisant les méthodes de celui-ci
     * @return void
     * @param rien
     */ 
    void sendServer();

    friend class Server;
    friend class Sensor;
    
private:
    int m_time; ///Interval de temps choisi par l'utilisateur
    Temperature m_temperature; ///Capteur de température
    Humidity m_humidity; ///Capteur d'humidité
    Light m_light; ///Capteur de lumière
    Pression m_pression; ///Capteur de pression
    Server m_server; ///Server lié au scheduler
};


#endif // SCHEDULER_H