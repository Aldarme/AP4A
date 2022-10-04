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
    while(true)
    {
        int valeurs[4] = {0, 0, 0, 0};
        valeurs[0] = m_hSensor.getData();
        valeurs[1] = m_lSensor.getData();
        valeurs[2] = m_pSensor.getData();
        valeurs[3] = m_tSensor.getData();

        m_server.consoleWrite(valeurs);
        m_server.fileWrite(valeurs);

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }    
}
