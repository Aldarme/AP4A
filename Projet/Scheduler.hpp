/**
 * @file Scheduler.hpp
 * @author Aurélien PETRA
 * @brief Fait le lien entre la classe sensor et la classe server et définie une horloge
 * @version 0.1
 * @date 2022-10-09
 *
 * @copyright Copyright (c) 2022
 *
 */

// Define guards
#ifndef SCHEDULER_H
#define SCHEDULER_H

#ifdef _WIN32
#include <windows.h>
#include <thread>
#else
#include <unistd.h>
#endif
#include "Temperature.hpp"
#include "Pressure.hpp"
#include "Light.hpp"
#include "Humidity.hpp"
#include "Packet.hpp"
#include "Server.hpp"

class scheduler
{
private:
    packet m_packet;

public:
    scheduler() : m_packet() {}
    scheduler(const scheduler &param_s) : m_packet(param_s.m_packet) {}
    ~scheduler() {}
    scheduler &operator=(const scheduler &);

    /**
     * @brief Met en pause le programme pendant 1 seconde
     *
     */
    void timer();

    /**
     * @brief Contient toute la boucle de génération, de transmission et d'écriture des données
     * @param server - Objet server avec avec lequel l'écriture des données est faite
     */
    void loop(server &);

    /**
     * @brief Récupère les données générés par les capteurs et les met dans l'attribut m_packet
     *
     * @return scheduler&
     */
    scheduler &getData(temperature, pressure, light_, humidity);

    /**
     * @brief Récupère la donnée générée par temperature et la met dans l'attribut m_packet
     * 
     * @return scheduler& 
     */
    scheduler &getTemp(temperature);

    /**
     * @brief Récupère la donnée générée par pressure et la met dans l'attribut m_packet
     * 
     * @return scheduler& 
     */
    scheduler &getPress(pressure);

    /**
     * @brief Récupère la donnée générée par light_ et la met dans l'attribut m_packet
     * 
     * @return scheduler& 
     */
    scheduler &getLight(light_);

    /**
     * @brief Récupère la donnée générée par humidity et la met dans l'attribut m_packet
     * 
     * @return scheduler& 
     */
    scheduler &getHumid(humidity);
};

#endif // SCHEDULER_H