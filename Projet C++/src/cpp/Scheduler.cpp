/*
@author BENEDUCI Marie
@file  Scheduler.cpp
@date 19/09/2022
@brief  Implementation de la Classe ayant pour objectif d'envoyer au Server les données des Sensor récupérées
*/

#include<cstdio>
#include<iostream>
#include<ctime>
#include <thread>
#include "../hpp/Scheduler.hpp"
#include "../hpp/Temperature.hpp"
#include "../hpp/Pression.hpp"
#include "../hpp/Humidity.hpp"
#include "../hpp/Light.hpp"
#include "../hpp/Server.hpp"


#define NUM_THREADS 4


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

        Pression *pression;
        pression = new Pression;

        // Création d'un objet Server
        Server server;
    
        // instanciation du delais de 2 secondes entre chaques relevé de valeurs
        int delay = 2;
        delay *= CLOCKS_PER_SEC;

        clock_t now = clock();
        
        while(clock() - now <delay);
        // Appels des differentes fonctions de la classe Server pour afficher dans la console et ecrire dans le fichier log (rendu intermediaire) les données récuperées des differents Sensors toutes les 2 secondes
        server.newStatement(i+1);
        // server.fileAndConsoleWrite<float>("Temperature" , temperature ->aleaGenVal(), "°C", i+1);
        // server.fileAndConsoleWrite<float>("Humidity" , humidity->aleaGenVal(), "%", i+1);
        // server.fileAndConsoleWrite<bool>("Light" , light->aleaGenVal(), "lm", i+1);
        // server.fileAndConsoleWrite<int>("Pression" , pression->getData(), "dB", i+1);








        // std::thread t1([]() {
        //     Server server;
        //     Light *light;
        //     light = new Light;

        //     int delay = 2;
        //     delay *= CLOCKS_PER_SEC;
        //     clock_t now = clock();
            
        //     while(clock() - now <delay);
        //         server.fileAndConsoleWrite("Light" , light->getData(), "lm", 1);

        // });
        // std::thread t2([]() {
        //     Server server;
        //     Humidity *humidity;
        //     humidity = new Humidity;

        //     int delay = 5;
        //     delay *= CLOCKS_PER_SEC;
        //     clock_t now = clock();
            
        //     while(clock() - now <delay);
        //         server.fileAndConsoleWrite("Humidity" , humidity->getData(), "%", 2);
            
        // });
        // std::thread t3([]() {
        //     Server server;
        //     Temperature *temperature;
        //     temperature = new Temperature;

        //     int delay = 1;
        //     delay *= CLOCKS_PER_SEC;
        //     clock_t now = clock();
            
        //     while(clock() - now <delay);
        //         server.fileAndConsoleWrite("Temperature" , temperature->getData(), "°C", 3);
        // });
        // std::thread t4([]() {
        //     Server server;
        //     Sound *sound;
        //     sound = new Sound;

        //     int delay = 10;
        //     delay *= CLOCKS_PER_SEC;
        //     clock_t now = clock();
            
        //     while(clock() - now <delay);
        //         server.fileAndConsoleWrite("Sound" , sound->getData(), "dB", 4);
        // });

        // t1.join();
        // t2.join();
        // t3.join();
        // t4.join();

        // std::thread threads[4];

	    // threads[0] = std::thread(&Server::fileAndConsoleWrite<float>,"Temperature", &Temperature::getData,2);
	    // std::this_thread::sleep_for(std::chrono::milliseconds(100));	// Adding delay between threads, otherwise the console prints intertwine

	    // threads[1] = std::thread(&Server::fileAndConsoleWrite<int>,"Pression", &Pression::getData,5);
	    // std::this_thread::sleep_for(std::chrono::milliseconds(100));

	    // threads[2] = std::thread(&Server::fileAndConsoleWrite<float>,"Humidity", &Humidity::getData, 3);
	    // std::this_thread::sleep_for(std::chrono::milliseconds(100));

	    // threads[3] = std::thread(&Server::fileAndConsoleWrite<bool>,"Light", &Light::getData,4);

        // for (int i = 0; i < 4; ++i) {
        //     threads[i].join();
        // }


    
    }

    


return 0;

}