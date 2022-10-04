/*
@author BENEDUCI Marie
@file  Scheduler.hpp
@date 19/09/2022
@brief  Déclaration de la Classe ayant pour objectif d'envoyer au Server les données des Sensor récupérées
*/

#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

class Scheduler
{
public:
    Scheduler(); // Constructeur par défaut
    ~Scheduler(); // Destructeur
    Scheduler (const Scheduler&); // Constructeur de recopie
    Scheduler &operator=(const Scheduler&); // Opérateur d'affectation
    int getSensorData(); // Fonction de récuperation des données des Sensors

};



#endif