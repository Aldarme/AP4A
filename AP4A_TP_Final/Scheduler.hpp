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
#include "Temperature.hpp"
#include "Pression.hpp"
#include "Humidity.hpp"
#include "Light.hpp"


class Scheduler{
    public:
        //Forme Canonique
        Scheduler(); 
        virtual ~Scheduler()= default; 
        Scheduler(const Scheduler& scheduler_p); 
        Scheduler& operator=(const Scheduler& scheduler_p)
        {
            m_mode=scheduler_p.m_mode;
            m_duree=scheduler_p.m_duree;                
            m_comptT=scheduler_p.m_comptT;
            m_comptH=scheduler_p.m_comptH;
            m_comptP=scheduler_p.m_comptP;
            m_comptL=scheduler_p.m_comptL;
            m_comptS=scheduler_p.m_comptS;
            return *this;
        } 
        
        void ScheStart();           //Methode de depart permet de faire le choix du mode d'affichage/sauvegarde et de la durée de la simulation

    private:
        Temperature m_SensorTemp;   //Capteur de température
        Humidity m_SensorHum;       //Capteur d'humidité
        Pression m_SensorPress;     //Capteur de pression
        Light m_SensorLight;        //Capteur de lumière
        Server monServer;           //Serveur à qui ont envoie les données
        Sac_struct sac;             //Structure qui contient les valeurs des capteurs
        int m_mode;                 //Varibale qui determine le mode d'affichage et/ou d'enregistrement des données des capteurs
        void monTimer(int);         //Fonction qui permet de récupérer les donées et de les envoyer au serveur 
        int m_duree;                //Variable de la durée du temps de simulation
        int m_comptT, m_comptH, m_comptP, m_comptL, m_comptS;   //Compteur des fréquences de chaque capteurs et de l'envoie au serveur
        
       
        
};
#endif //SCHEDULER_H