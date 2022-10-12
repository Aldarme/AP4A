/**
 * @file Scheduler.hpp
 * @author Loric Ravassard
 * @brief Récupère les données du sensor, envoie les données au serveur, gère les cycles
 * @version 1
 * @date 2022-09-28
 */

#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "./Sensor/Sensor.hpp"
#include "./Sensor/Humidity.hpp"
#include "./Sensor/Light.hpp"
#include "./Sensor/Pressure.hpp"
#include "./Sensor/Temperature.hpp"
#include "Package.hpp"
#include "Server.hpp"

/**
 * @class Scheduler
 * @brief Récupère les données du sensor, envoie les données au serveur, gère les cycles
 */
class Scheduler
{
  private:
    Humidity m_humidity;        ///instance de la classe Humidity pour avoir des valeurs
    Light m_light;              ///instance de la classe Light pour avoir des valeurs
    Pressure m_pressure;        ///instance de la classe Pressure pour avoir des valeurs
    Temperature m_temperature;  ///instance de la classe Temperature pour avoir des valeurs
    Server m_server;            ///instance de la classe Server pour envoyer les données
    Package m_dataPkg;          ///instance de la classe Package pour pouvoir mettre les données dans un seul packet
  public:
    Scheduler(){};
    Scheduler(const Scheduler& other_p);
    virtual ~Scheduler(){};
    Scheduler operator=(const Scheduler& other_p);

    /**
     * @brief récupère les données de tous les capteurs
     * 
     */
    void getAllData();

    /**
     * @brief regroupe les données dans un seul packet et les envoie au server
     * 
     */
    void sendData();

    /**
     * @brief gère le temps de cycle, le programme s'execute pendant minute_p minutes
     * 
     * @param time_p 
     * @param wait_p 
     */
    void run(int time_p, int wait_p);

};

#endif