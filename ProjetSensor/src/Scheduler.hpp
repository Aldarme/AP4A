/**
 * @author Thibaud Leclere <thibaud.leclere@utbm.fr>
 * @file Scheduler.hpp
 * @date 28/09/2022
 * @brief Définition de la class Scheduler
 * @brief Récupère les données des Sensors toutes les secondes et les envoie à la classe Server
 */

// Define guards
#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <chrono>
#include <thread>

#include "Server.hpp"
#include "Sensor.hpp"

class Scheduler
{
private:
    Server m_server;                // Instance de Server
    HumiditySensor m_hSensor;       // Capteur d'humidité
    LightSensor m_lSensor;          // Capteur de lumière
    PressureSensor m_pSensor;       // Capteur de pression atmosphérique
    TemperatureSensor m_tSensor;    // Capteur de température

public:
    //Forme canonique
    Scheduler();
    ~Scheduler();
    Scheduler(const Scheduler& s);
    Scheduler& operator=(const Scheduler& s);

    /**
     * @brief Récupère les données des capteurs toutes les secondes et les envoie à la classe Server
     */
    void awaitSensors();
};

#endif // SCHEDULER_H
