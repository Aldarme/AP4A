/**
 * @author Jules Ferlin
 * @file scheduler.cpp
 * @date 03/10/2022
 * @brief Fichier source contenant l'implémentation des méthodes de la classe Scheduler
 */


#include "scheduler.hpp"

Scheduler::Scheduler() : m_duration(0), m_humidite(), m_light(), m_pression(), m_temperature(), m_server()
{}

Scheduler::Scheduler(const Scheduler& s_p) : m_duration(s_p.m_duration), m_temperature(s_p.m_temperature), m_pression(s_p.m_pression),
                                             m_light(s_p.m_light), m_humidite(s_p.m_humidite), m_server(s_p.m_server)
{}

Scheduler::~Scheduler() = default;

Scheduler& Scheduler::operator=(const Scheduler& scheduler_p)
{
    this->m_humidite = scheduler_p.m_humidite;
    this->m_light = scheduler_p.m_light;
    this->m_pression = scheduler_p.m_pression;
    this->m_temperature = scheduler_p.m_temperature;
    this->m_duration = scheduler_p.m_duration;
    return *this;
}

void Scheduler::setDuration()
{
    int durer;
    std::cout << "Entre la durer de la simulation:";
    std::cin >> durer;
    while (durer < 0)
    {
        std::cout << "Vous devez entrer une valeur supérieur à 0" << std::endl << "Entre la durer de la simulation:";
        std::cin >> durer;
    }
    this->m_duration = durer;
}

void Scheduler::startSimulation()
{
    this->setDuration();
    this->m_server.toggleConsolWrite();
    this->m_server.toggleLogWrite();
    clock_t start;
    start = (clock()/CLOCKS_PER_SEC);
    while (((clock()/CLOCKS_PER_SEC) - start) < this->m_duration)
    {
        this->m_server.consolWrite(this->m_humidite.getName(), this->m_humidite.getData(), this->m_humidite.getUnite());
        this->m_server.consolWrite(this->m_light.getName(), this->m_light.getData(), this->m_light.getUnite());
        this->m_server.consolWrite(this->m_temperature.getName(), this->m_temperature.getData(), this->m_temperature.getUnite());
        this->m_server.consolWrite(this->m_pression.getName(), this->m_pression.getData(), this->m_pression.getUnite());
        this->m_server.fileWrite(this->m_humidite.getName(), this->m_humidite.getData(), this->m_humidite.getUnite());
        this->m_server.fileWrite(this->m_light.getName(), this->m_light.getData(), this->m_light.getUnite());
        this->m_server.fileWrite(this->m_temperature.getName(), this->m_temperature.getData(), this->m_temperature.getUnite());
        this->m_server.fileWrite(this->m_pression.getName(), this->m_pression.getData(), this->m_pression.getUnite());

    }
}