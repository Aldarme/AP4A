/**
 * @author Augustin Athané
 * @file Scheduler.cpp
 * @date 24/09/2022
 * @brief Le scheduler est composé d'un ensemble de capteurs et d'un serveur. Il est chargé d'ordonner les données reçus par les capteurs
 * et de les envoyer sur le serveur
 */
#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

#include <iostream>
#include <cstdlib>
#include "../Sensor/Sensor.cpp"
#include "../Server/Server.cpp"

class Scheduler
{
    private :
        Temperature capt_temperature;
        Humidity capt_humidity;
        Light capt_light;
        Pression capt_pression;
        Server server;
        

    public :
        //Constructeur par défault
        Scheduler();

        //Constructeur paramétré
        Scheduler(Temperature t, Humidity h, Light l, Pression p, Server s);

        //Constructeur de recopie
        Scheduler(const Scheduler &other);

        //Destructeur
        ~Scheduler();

        void startSimulation(int time_, bool doLog_, bool doPrintConsole_);

};


#endif // SCHEDULER_HPP