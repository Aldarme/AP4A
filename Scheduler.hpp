/**
 * @author Planchin Arnaud
 * @file Scheduler.hpp
 * @date 03/10/2022
 * @brief Récpère les données des Sensor et les envoie au Server
 */

#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <iostream>
#include "Sensor.hpp"

// Creer un objet a partir d'une classe : -> intantiation
// Instantier 4 capteurs
// 

class Scheduler
{
private:

    Temperature temp;
    Humidity hum;
    Light lum;
    Pression pres; 

public:


    /**
     * @brief 
     * @return Rien
     * @param
     */
    void Scheduler(){};

    void getAll(); //appel methode de sensor 

    void serverSendData();

    void wait();
    
}

#endif // SCHEDULER_H