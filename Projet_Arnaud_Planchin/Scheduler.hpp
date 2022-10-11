/**
 * @author Planchin Arnaud
 * @file Scheduler.hpp
 * @date 03/10/2022
 * @brief Récpère les données des Sensor et les envoie au Server au travers d'un paquet de donnée
 */

#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "Server.hpp"
#include <iostream>
#include <Windows.h>
using namespace std;

class Scheduler
{
public:

    Paquet scheduler_Pack;

    /**
     * @brief Forme Canonique de Coplien de la classe Scheduler
     */
    Scheduler():scheduler_Pack(){}
    ~Scheduler(){}
    Scheduler(const Scheduler& sched):scheduler_Pack(sched.scheduler_Pack){}
    

    /**
     * @brief Récupère toutes les valeurs de chaque Sensor et les regroupe en un pacquet de donnée
     * @return un Scheduler qui a comme attribut le paquet créé
     * @param - aucun
     */
    Scheduler getAll(); 

    /**
     * @brief Envoie le pacquet de Scheduler vers le Server
     * @return Rien
     * @param serv - un objet de type Server
     */
    void serverSendData(Server& serv);

    /**
     * @brief Fait une pause
     * @return Rien
     * @param - aucun
     */
    void wait();
    
};

#endif // SCHEDULER_H