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
    Temperature m_temperature_scheduler;
    Humidity m_humidity_scheduler;
    Light m_light_scheduler;
    Pression m_pression_scheduler;

}

//constructeur par valeurs
Scheduler::Scheduler(Temperature t, Humidity h, Light l, Pression p)
{

    this->m_temperature_scheduler = t;
    this->m_humidity_scheduler = h;
    this->m_light_scheduler = l;
    this->m_pression_scheduler = p;

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
Scheduler::~Scheduler()
{


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
 * @param int m_temps_restant, m_temps_temperature, m_temps_humidity, m_temps_light,
 * m_temps_pression, Server s, char log, affichage
 */
void Scheduler::takeData(int m_temps_restant, int m_temps_temperature, int m_temps_humidity,
int m_temps_light, int m_temps_pression, Server& s, char log, char affichage)
{

    //température
    if(m_temps_restant % m_temps_temperature == 0)
    {

        m_temperature_scheduler.m_valeur= m_temperature_scheduler.aleaGenVal();

        if(log == 'Y' && affichage == 'Y')
        {

            s.fileWrite(this->m_temperature_scheduler);
            s.consoleWrite(this->m_temperature_scheduler);

        }
        else if(log == 'N' && affichage == 'Y')
        {

            s.consoleWrite(this->m_temperature_scheduler);

        }
        else if(log == 'Y' && affichage == 'N')
        {

            s.fileWrite(this->m_temperature_scheduler);
        }
        else
        {

        }

    }
    
    //humidity
    if (m_temps_restant % m_temps_humidity == 0)
    {

        m_humidity_scheduler.m_valeur = m_humidity_scheduler.aleaGenVal();

        if(log == 'Y' && affichage == 'Y')
        {

            s.fileWrite(this->m_humidity_scheduler);
            s.consoleWrite(this->m_humidity_scheduler);

        }
        else if(log == 'N' && affichage == 'Y')
        {

            s.consoleWrite(this->m_humidity_scheduler);

        }
        else if(log == 'Y' && affichage == 'N')
        {

            s.fileWrite(this->m_humidity_scheduler);

        }
        else
        {
            
        }
    }
    
    //light
    if (m_temps_restant % m_temps_light == 0)
    {

        m_light_scheduler.m_valeur = m_light_scheduler.aleaGenVal();

        if(log == 'Y' && affichage == 'Y')
        {

            s.fileWrite(this->m_light_scheduler);
            s.consoleWrite(this->m_light_scheduler);

        }
        else if(log == 'N' && affichage == 'Y')
        {

            s.consoleWrite(this->m_light_scheduler);

        }
        else if(log == 'Y' && affichage == 'N')
        {

            s.fileWrite(this->m_light_scheduler);

        }
        else
        {
            
        }
    }
    
    //pression
    if(m_temps_restant % m_temps_pression == 0)
    {

        m_pression_scheduler.m_valeur = m_pression_scheduler.aleaGenVal();

        if(log == 'Y' && affichage == 'Y')
        {

            s.fileWrite(this->m_pression_scheduler);
            s.consoleWrite(this->m_pression_scheduler);

        }
        else if(log == 'N' && affichage == 'Y')
        {

            s.consoleWrite(this->m_pression_scheduler);

        }
        else if(log == 'Y' && affichage == 'N')
        {

            s.fileWrite(this->m_pression_scheduler);

        }
        else
        {
            
        }
    }

    //this_thread::sleep_for(chrono::milliseconds(1000)); //on ne l'utilise pas ici car
    //cela entraîne un décalage

}	
