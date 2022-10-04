/**
 * @author Jules Ferlin
 * @file scheduler.hpp
 * @date 03/10/2022
 * @brief Fichier header contenant la définition de la classe Scheduler
 */

#ifndef PROJET_AP4A_SCHEDULER_HPP
#define PROJET_AP4A_SCHEDULER_HPP

#include "sensor.hpp"
#include "server.hpp"

class Scheduler {
private:
    Humidite m_humidite;
    Light m_light;
    Pression m_pression;
    Temperature m_temperature;
    Server m_server;
    int m_duration;
    float data[4];

    /**
     * @brief Demande à l'utilisateur d'entrer la durer de la simulation
     */
    void setDuration();
public:
    // Forme canonique
    Scheduler();
    Scheduler(const Scheduler& scheduler_p);
    ~Scheduler();
    Scheduler& operator=(const Scheduler& scheduler_p);

    void startSimulation();
};


#endif //PROJET_AP4A_SCHEDULER_HPP
