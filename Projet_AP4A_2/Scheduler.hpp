/**
 * @author choulot_hugo
 * @file Scheduler.hpp
 * @date 23/09/2022
 * @brief Cette classe permet de gérer les flux de données envoyé par les capteurs
 */

//
// Define guards
#ifndef Projet_AP4A_SCHEDULER_H
#define Projet_AP4A_SCHEDULER_H

#include "Server.hpp"
#include "Temperature.hpp"
#include "Humidity.hpp"
#include "Light.hpp"
#include "Pression.hpp"

//class Temperature; "has not been declared"
//class Humidity; "has not been declared"
//class Light; "has not been declared"
//class Pression; "has not been declared"

class Server;

/**
 * @class
 * @brief
 */
class Scheduler
{

    protected :

    //attributs
    //float m_temperature_scheduler;
    //float m_humidity_scheduler;
    //bool m_light_scheduler;
    //int m_pression_scheduler;

    Temperature m_temperature_scheduler;
    Humidity m_humidity_scheduler;
    Light m_light_scheduler;
    Pression m_pression_scheduler;

    public :

    //Définition de la forme canonique
    
    //constructeur par défaut
    Scheduler();

    //constructeur par valeurs
    Scheduler(Temperature t, Humidity h, Light l, Pression p);

    //constructeur par recopie
    Scheduler(const Scheduler& sc);

    //destructeur
    ~Scheduler();

    //operator
    Scheduler& operator=(const Scheduler& sc);

    /**
     * @brief Permet de récupérer les données des capteurs avec une certaine intervalle de temps
     * @return void
     * @param Capteurs Temperature, Humidity, Light et Pression + int intervalle de temps
     */
    void takeData(int m_intervalle_temps, int m_temps_temperature, int m_temps_humidity, int m_temps_light, int m_temps_pression, Server& s, char log, char affichage);

    //déclaration d'ami avec Server
    friend class Server;

};

#endif // Projet_AP4A_SCHEDULER_H
