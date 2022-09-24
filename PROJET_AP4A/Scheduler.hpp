/**
 * @author RENON Emilien
 * @file Scheduler.hpp
 * @date 23/09/2022
 * @brief Recupérer les données et les envoyer au serveur
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

/**
 * @class Scheduler
 * @brief La classe Scheduler permettra de créer les périodes de temps
 */
class Scheduler
{
public:
    // Definition de la forme canonique
    Scheduler();
    Scheduler(Server &param_server,Temperature &param_temperature,Humidity &param_humidity,Light &param_light,Pression &param_pression);
    Scheduler(Scheduler &s);
    ~Scheduler(){};
    // ...

    /**
     * @brief Récupérer les valeurs
     * @return void
     * @param int,int,int,int
     */ 
    void setValue();

private:
    int m_time; ///Interval de temps choisi par l'utilisateur
    Temperature m_temperature;
    Humidity m_humidity;
    Light m_light;
    Pression m_pression;
    Server m_server;
};

#endif // SCHEDULER_H