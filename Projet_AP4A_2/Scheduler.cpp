/**
 * @author choulot_hugo
 * @file Scheduler.cpp
 * @date 23/09/2022
 * @brief Cette classe permet de gérer les flux de données envoyé par les capteurs
 */

#include <iostream>
#include <thread>
#include <chrono>

#include "Scheduler.hpp"

using namespace std;

//constructeur par défaut
Scheduler::Scheduler()
{

    m_temperature_scheduler = 0.;
    m_humidity_scheduler = 0.;
    m_light_scheduler = false;
    m_pression_scheduler = 0;

}

//constructeur par valeurs
Scheduler::Scheduler(float t, float h, bool l, int p)
{

    m_temperature_scheduler = t;
    m_humidity_scheduler = h;
    m_light_scheduler = l;
    m_pression_scheduler = p;

}

//constructeur par recopie
Scheduler::Scheduler(const Scheduler& sc)
{

    this->m_temperature_scheduler = sc.m_temperature_scheduler;
    this->m_humidity_scheduler = sc.m_humidity_scheduler;
    this->m_light_scheduler = sc.m_light_scheduler;
    this->m_pression_scheduler = sc.m_pression_scheduler;

}

//destructeur
Scheduler::~Scheduler(){

    cout << "Destructeur appelle\n" << endl;

}

//operator
Scheduler& Scheduler::operator=(const Scheduler& sc)
{

    this->m_temperature_scheduler = sc.m_temperature_scheduler;
    this->m_humidity_scheduler = sc.m_humidity_scheduler;
    this->m_light_scheduler = sc.m_light_scheduler;
    this->m_pression_scheduler = sc.m_pression_scheduler;

    return *this;

}

/**
 * @brief Permet de récupérer les données des capteurs avec une certaine intervalle de temps
 * @return void
 * @param Capteurs Temperature, Humidity, Light et Pression + int intervalle de temps
 */
void Scheduler::takeData(Temperature& t, Humidity& h, Light& l, Pression& p, int m_intervalle_temps)
{

    m_temperature_scheduler = t.aleaGenVal();
    m_humidity_scheduler = h.aleaGenVal();
    m_light_scheduler = l.aleaGenVal();
    m_pression_scheduler = p.aleaGenVal();

    this_thread::sleep_for(chrono::milliseconds(m_intervalle_temps*1000));

}	
