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

#include "Sensor.hpp"
#include "Server.hpp"

class Temperature;
class Humidity;
class Light;
class Pression;

/**
 * @class
 * @brief
 */
class Scheduler
{

    private :

    //attributs
    float m_temperature_scheduler;
    float m_humidity_scheduler;
    bool m_light_scheduler;
    int m_pression_scheduler;

    public :

    //Définition de la forme canonique
    
    //constructeur par défaut
    Scheduler();

    //constructeur par valeurs
    Scheduler(float t, float h, bool l, int p);

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
    void takeData(Temperature& t, Humidity& h, Light& l, Pression& p, int m_intervalle_temps);

    //déclaration d'ami avec Server
    friend class Server;

};

#endif // Projet_AP4A_SCHEDULER_H
