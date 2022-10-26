/**
 * @file Scheduler.hpp
 * @author Loric Ravassard
 * @brief Récupère les données du sensor, envoie les données au serveur, gère les cycles
 * @version 2
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
    Package<float> m_dataHum;   ///instance de la classe Package pour stocker les données d'humidité       
    Package<float> m_dataTemp;  ///instance de la classe Package pour stocker les données de température
    Package<int> m_dataPress;   ///instance de la classe Package pour stocker les données de pression
    Package<bool> m_dataLight;  ///instance de la classe Package pour stocker les données de lumière
    bool m_stopSimulation;      ///booléen qui arrête la simulation quand il est a true
  public:
    Scheduler() : m_stopSimulation(false){};
    Scheduler(const Scheduler& other_p) : m_stopSimulation(other_p.m_stopSimulation){};
    virtual ~Scheduler(){};
    Scheduler& operator=(const Scheduler& other_p);

    /**
     * @brief récupère les données d'un capteur et les stock dans un packet
     * 
     * @param sensor_p
     * @param pack_p 
     */
    template <typename T> void getSensorData(Sensor<T>* sensor_p, Package<T>* pack_p)
    {
      std::time_t now;
      char buffer [80];
      std::time(&now);
      #pragma warning(suppress : 4996)  //car localtime est dépréciée. C'est un warning mais ça devient une erreur en C++ 14
      std::strftime(buffer,sizeof(buffer),"%d/%m/%Y %H:%M:%S", std::localtime(&now)); //récupère la date a laquelle on a récupéré les données

      pack_p->addMeasure(buffer, sensor_p->getName(), sensor_p->getData(), sensor_p->getUnit());
    };

    /**
     * @brief envoie les données d'un packet au server
     * 
     * @param data_p 
     */
    template <typename T> void sendData(Package<T> data_p)
    {
      m_server.dataRcv(data_p);
    };

    /**
     * @brief gère le temps de cycle, le programme s'execute tant que l'utilisateur ne l'arrête pas 
     *  
     */
    void run();

    /**
     * @brief exécuté par un autre thread, change la variable m_stopSimulation en fonction du choix de l'utilisateur
     * 
     */
    void endSimulation();
};

#endif