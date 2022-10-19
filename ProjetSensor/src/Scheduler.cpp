/**
 * @author Thibaud Leclere <thibaud.leclere@utbm.fr>
 * @file Scheduler.cpp
 * @date 28/09/2022
 * @brief Implémentation de la class Scheduler
 * @brief Récupère les données des Sensors toutes les secondes et les envoie à la classe Server
 */

#include "Scheduler.hpp"

Scheduler::Scheduler() = default;
Scheduler::~Scheduler() = default;
Scheduler::Scheduler(const Scheduler& s) = default;
Scheduler& Scheduler::operator=(const Scheduler& s) = default;

void Scheduler::awaitSensors()
{
    //Demande à l'utilisateur où envoyer les données (console et/ou logs)
    m_server.askOutputs();

    //On indique les fréquences voulues pour chaque sensor
    m_hSensor.setFreq(1);
    m_lSensor.setFreq(4);
    m_pSensor.setFreq(2);
    m_tSensor.setFreq(3);

    //Boucle infinie imitant un serveur tournant en boucle
    //Un compteur (i) est utilisé pour compter les secondes
    int i = 1;
    while(true)
    {
        //Si un capteur a fait un cycle, il envoie ses données au serveur, qui les affiche
        if(m_hSensor.getFreq() != 0 && i % m_hSensor.getFreq() == 0)
        {
            m_server.rcvData(m_hSensor.getData());
        }
        if(m_lSensor.getFreq() != 0 && i % m_lSensor.getFreq() == 0)
        {
            SensorData data = m_lSensor.getData();
            data.sensorValue = (data.sensorValue == "0" ? "off" : "on");
            m_server.rcvData(data);
        }
        if(m_pSensor.getFreq() != 0 && i % m_pSensor.getFreq() == 0)
        {
            m_server.rcvData(m_pSensor.getData());
        }
        if(m_tSensor.getFreq() != 0 &&i % m_tSensor.getFreq() == 0)
        {
            m_server.rcvData(m_tSensor.getData());
        }

        //Incrémentation du compteur de temps, et on endort le programme pour une seconde
        ++i;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }    
}
