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
#include<sstream>

#include <iostream>
#include <future>
#include <mutex>
#include <thread>
#include <chrono>

#include "../hpp/Scheduler.hpp"
#include "../hpp/Temperature.hpp"
#include "../hpp/Pression.hpp"
#include "../hpp/Humidity.hpp"
#include "../hpp/Light.hpp"
#include "../hpp/Server.hpp"

#define NUM_THREADS 4

Server server;


Scheduler::Scheduler()
{
}

Scheduler::~Scheduler(){
}


void Scheduler::task1(int i){
    Temperature *temperature;
    temperature = new Temperature;

    server.fileAndConsoleWrite("Temperature" , std::to_string(temperature->getData()), "°C", i+1);

}

void Scheduler::task2(int i){
    Light *light;
    light = new Light;

    server.fileAndConsoleWrite("Light" , std::to_string(light->getData()), "", i+1);

}

void Scheduler::task3(int i){

    Humidity *humidity;
    humidity = new Humidity;

    server.fileAndConsoleWrite("Humidity" , std::to_string(humidity->getData()), "%", i+1);


}

void Scheduler::task4(int i){

    Pression *pression;
    pression = new Pression;

    server.fileAndConsoleWrite("Pression" , std::to_string(pression->getData()), "Pa", i+1);

}


int Scheduler::getSensorData()
{


    for(int i =0;i<15; i++){ // création d'une boucle de 5 instances pour recuperer 5 fois les valeurs des sensor

        int delay = 1;
        delay *= CLOCKS_PER_SEC;

        clock_t now = clock();
        
        while(clock() - now <delay);
            // Appels des differentes fonctions de la classe Server pour afficher dans la console et ecrire dans le fichier log (rendu intermediaire) les données récuperées des differents Sensors toutes les 2 secondes
            server.newStatement(i+1);

            if ((i+1)%2 == 0){
                task1(i);
            }

            if ((i+1)%6 == 0){
                task2(i);
            }

            if ((i+1)%5 == 0){
                task3(i);
            }

            if ((i+1)%1 == 0){
                task4(i);
            }

            

            // std::thread t1(&task1,i);







    
        // instanciation du delais de 2 secondes entre chaques relevé de valeurs
        // int delay = 2;
        // int delay1 = 5;
        // int delay2 = 6;
        // int delay3 = 1;        

        // delay *= CLOCKS_PER_SEC;
        // delay1 *= CLOCKS_PER_SEC;
        // delay2 *= CLOCKS_PER_SEC;
        // delay3 *= CLOCKS_PER_SEC;


        

        
        // int arr[]={1*CLOCKS_PER_SEC,2*CLOCKS_PER_SEC,3*CLOCKS_PER_SEC,4*CLOCKS_PER_SEC,5*CLOCKS_PER_SEC};   //array initialization
        // clock_t now = clock();
        //     for(int sec : arr)
        //     {
        //         while(clock() - now <sec);
        //         std::cout<<sec<<" ";
        //     }

        
   


        
        
        // while(clock() - now <delay);
        //     server.newStatement(i+1);
        //     server.fileAndConsoleWrite("Temperature" , std::to_string(temperature->getData()), "°C", i+1);
        

        // while(clock() - now <delay1);
        //     server.newStatement(i+1);
        //     server.fileAndConsoleWrite("Humidity" , std::to_string(humidity->getData()), "%", i+1);


        // while(clock() - now <delay2);
        //     server.newStatement(i+1);
        //     server.fileAndConsoleWrite("Light" , std::to_string(light->getData()), "", i+1);


        // while(clock() - now <delay3);
        //     server.newStatement(i+1);
        //     server.fileAndConsoleWrite("Pression" , std::to_string(pression->getData()), "Pa", i+1);
        

        
        // Appels des differentes fonctions de la classe Server pour afficher dans la console et ecrire dans le fichier log (rendu intermediaire) les données récuperées des differents Sensors toutes les 2 secondes
        // server.newStatement(i+1);
        

        // server.fileAndConsoleWrite("Temperature" , std::to_string(temperature->getData()), "°C", i+1);

        // server.fileAndConsoleWrite("Humidity" , std::to_string(humidity->getData()), "%", i+1);

        // server.fileAndConsoleWrite("Light" , std::to_string(light->getData()), "", i+1);

        // server.fileAndConsoleWrite("Pression" , std::to_string(pression->getData()), "Pa", i+1);


        //auto fa = std::async( std::launch::async, server->fileAndConsoleWrite("Temperature", std::to_string(temperature->getData()), "°C", i+1));
        // auto fb = std::async( std::launch::async, counter, 0, 80, 50, 'b' ) ;





        // std::thread t1([]() {
        //     Server server;
        //     Light *light;
        //     light = new Light;

        //     int delay = 2;
        //     delay *= CLOCKS_PER_SEC;
        //     clock_t now = clock();
            
        //     while(clock() - now <delay);
        //         server.fileAndConsoleWrite("Light" , std::to_string(light->getData()), "", 2);

        // });
        // std::thread t2([]() {
        //     Server server;
        //     Humidity *humidity;
        //     humidity = new Humidity;

        //     int delay = 5;
        //     delay *= CLOCKS_PER_SEC;
        //     clock_t now = clock();
            
        //     while(clock() - now <delay);
        //         server.fileAndConsoleWrite("Humidity" , std::to_string(humidity->getData()), "%", 2);
            
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

      // main thread waits for the thread t to finish
    

    


return 0;

}