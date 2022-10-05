/**
 *@author Lola ROQUILLON 
 *@file Scheduler.hpp
 *@date 28/09/2022
 *@brief Cette classe synchronise les donées des capteurs et les envois au serveur à intervalle régulier
 */

#ifndef SCHEDULER_H
#define SCHEDULER_H
#include "Sensor.hpp"
#include "Server.hpp"

class Scheduler{
    public:
        Scheduler(); //constructeur par default
        ~Scheduler(); //destructeur

    private:
        Sensor m_SensorTemp;    //capteur de température
        Sensor m_SensorHum;     //capteur d'humidité
        Sensor m_SensorPress;   //capteur de pression
        Sensor m_SensorLight;   //capteur de lumière
        Server monServer;       //Serveur à qui ont envoie les données
        int m_mode;             // varibale qui determine le mode d'affichage et/ou d'enregistrement des données des capteurs
        void monTimer();        //fonction qui permet de récupérer les donées et de les envoyer au serveur toutes les 8 secondes
       
        
};
#endif //SCHEDULER_H