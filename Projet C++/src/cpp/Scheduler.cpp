/*
@author BENEDUCI Marie
@file  Scheduler.cpp
@date 19/09/2022
@brief  Implementation de la Classe ayant pour objectif d'envoyer au Server les données des Sensor récupérées
*/

#include<cstdio>
#include<iostream>
#include<ctime>
#include "../hpp/Scheduler.hpp"
#include "../hpp/Temperature.hpp"
#include "../hpp/Sound.hpp"
#include "../hpp/Humidity.hpp"
#include "../hpp/Light.hpp"
#include "../hpp/Server.hpp"



Scheduler::Scheduler()
{
}

Scheduler::~Scheduler(){
    
}

int Scheduler::getSensorData()
{
    for(int i =0;i<5; i++){ // création d'une boucle de 5 instances pour recuperer 5 fois les valeurs des sensor
        
        //Création d'objets dynamiques pour les differents Sensors stpécifiques, classes filles de la classe Sensor
        Temperature *temperature;
        temperature = new Temperature;
        
        Light *light;
        light = new Light;

        Humidity *humidity;
        humidity = new Humidity;

        Sound *sound;
        sound = new Sound;

        // Création d'un objet Server
        Server server;
    
        // instanciation du delais de 2 secondes entre chaques relevé de valeurs
        int delay = 2;
        delay *= CLOCKS_PER_SEC;

        clock_t now = clock();
        
        while(clock() - now <delay);
        // Appels des differentes fonctions de la classe Server pour afficher dans la console et ecrire dans le fichier log (rendu intermediaire) les données récuperées des differents Sensors toutes les 2 secondes
        server.newStatement(i+1);
        server.fileAndConsoleWrite("Temperature" , temperature->getData(), "°C");
        server.fileAndConsoleWrite("Humidity" , humidity->getData(), "%");
        server.fileAndConsoleWrite("Light" , light->getData(), "lm");
        server.fileAndConsoleWrite("Sound" , sound->getData(), "dB");


    }


return 0;

}