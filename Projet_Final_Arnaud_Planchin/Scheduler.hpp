/**
 * @author Planchin Arnaud
 * @file Scheduler.hpp
 * @date 03/10/2022
 * @brief Récpère les données des Sensor et les envoie au Server au travers d'un paquet de donnée
 */

#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "Server.hpp"


class Scheduler
{
private:

    // Attributs d'un Scheduler
    Paquet scheduler_Pack;

public:

    /**
     * @brief Forme Canonique de Coplien de la classe Scheduler
     */
    Scheduler():scheduler_Pack(){}
    virtual ~Scheduler(){}
    Scheduler(const Scheduler& sched):scheduler_Pack(sched.scheduler_Pack){}
    

    /**
     * @brief Récupère toutes les valeurs de chaque Sensor et les regroupe en un paquet de donnée
     * @return Un Scheduler qui a comme attribut le paquet créé
     */
    Scheduler getAll(); 

    /**
     * @brief Envoie le paquet de Scheduler vers le Server
     * @param serv - un objet de type Server
     * @param temps - "temps du programme"
     */
    void serverSendData(Server& serv,int temps);

    /**
     * @brief Fait une pause
     * @param pauses_secondes temps de pause en seconde
     */
    void wait(int pauses_secondes);
    
};


#endif // SCHEDULER_H