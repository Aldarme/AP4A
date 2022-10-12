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
#include "Temperature.hpp"
#include "Pression.hpp"
#include "Humidity.hpp"
#include "Light.hpp"


/**
 * @class Scheduler
 * @brief La classe Scheduler permettra de créer les périodes de temps
 */

class Scheduler
{
public:
    // Definition de la forme canonique
    Scheduler();
    Scheduler(Server &param_server,Temperature<float> &param_temperature,Humidity<float> &param_humidity,Light<bool> &param_light,Pression<int> &param_pression);
    Scheduler(Scheduler &s);
    ~Scheduler(){};
    // ...

    /**
     * @brief Fonction qui récupère les données des capteurs et envoi les valeurs des capteurs au serveur en utilisant les méthodes de celui-ci
     * @return void
     * @param rien
     */ 
    void sendServer(int param_time_occur,int param_time_temperature,int param_time_pression,int param_time_light,int param_time_humidity);
    

    friend class Server;
    template <class T> class Sensor;
    
private:
    Temperature<float> m_temperature; ///Capteur de température
    Humidity<float> m_humidity; ///Capteur d'humidité
    Light<bool> m_light; ///Capteur de lumière
    Pression<int> m_pression; ///Capteur de pression
    Server m_server; ///Server lié au scheduler
};


#endif // SCHEDULER_H