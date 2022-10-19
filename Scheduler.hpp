/**
* @author laduguie
* @file Scheduler.hpp
* @date 28/09/2022
* @brief Définition de la classe Scheduler
*/

#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "Humidity.hpp"
#include "Light.hpp"
#include "Pressure.hpp"
#include "Temperature.hpp"
#include "Server.hpp"
#include "Sensor.hpp"

class Server; /*on initialise la classe server au début pour avoir accès a tous ses éléments*/

class Scheduler
{
    private:
        Server* pObjetServer;
        captor_data structDef;

        Sensor<float>* pCaptorHumidity;
        Sensor<bool>* pCaptorLight;
        Sensor<int>* pCaptorPressure;
        Sensor<float>* pCaptorTemp;

        /*on créé l'objet server et la structure qui va contenir les données des capteurs*/
      

    public:
        Scheduler() //constructeur par defaut, on créé les objets
        {
            pCaptorHumidity = new Humidity();
            pCaptorLight = new Light();
            pCaptorPressure = new Pressure();
            pCaptorTemp = new Temperature();
            pObjetServer = new Server();
        }
        ~Scheduler()
        {
            delete(pCaptorHumidity, pCaptorLight, pCaptorPressure, pCaptorTemp, pObjetServer);
        }; //Destructeur
        
        void run(); //on déclare la fonction run

};

#endif
