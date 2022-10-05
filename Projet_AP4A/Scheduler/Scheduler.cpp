/**
 * @author Augustin Athané
 * @file Scheduler.cpp
 * @date 24/09/2022
 * @brief Le scheduler est composé d'un ensemble de capteurs et d'un serveur. Il est chargé d'ordonner les données reçus par les capteurs
 * et de les envoyer sur le serveur
 */

#include <iostream>
#include <cstdlib>
#include <chrono>
using namespace std::chrono;
#include <thread>
#include <ctime>
#include "Scheduler.hpp"
using namespace std;




//Constructeur par défault
Scheduler::Scheduler(){    
    //On appel symplement les constructeurs par défault à chaque fois
    capt_humidity = Humidity();
    capt_temperature = Temperature();
    capt_light = Light();
    capt_pression = Pression(); 
    server = Server();
}

//Constructeur paramétré
Scheduler::Scheduler(Temperature t, Humidity h, Light l, Pression p, Server s){
        capt_temperature = t;
        capt_humidity = h;
        capt_light = l;
        capt_pression = p;
        server = s;
}

//Constructeur de recopie
Scheduler::Scheduler(const Scheduler &other){
        capt_temperature = other.capt_temperature;
        capt_humidity = other.capt_humidity;
        capt_light = other.capt_light;
        capt_pression = other.capt_pression;
        server = other.server;
}

        //Destructeur
Scheduler::~Scheduler(){};

void Scheduler::startSimulation(int time_, bool doLog_, bool doPrintConsole_){
    //On créer un thread pour chaque capteur
    thread thread_temp(&Temperature::startSimulation, ref(capt_temperature)); 
    /** On utilise ref pour que les changements des sensors s'effectuent aussi dans ce thread
     * On ne peut pas passer une référence directement à un thread (&) car std::thread les copiera/déplacera. À la place il faut utiliser std::ref()
    **/
    thread thread_hum(&Humidity::startSimulation, ref(capt_humidity)); 
    thread thread_lig(&Light::startSimulation, ref(capt_light)); 
    thread thread_pres(&Pression::startSimulation, ref(capt_pression)); 

    server.updateDoLog(doLog_);
    server.updateDoPrintConsole(doPrintConsole_);
    thread thread_serv(&Server::startSimulation, ref(server)); // De même, on créer un thread pour le serveur

    for(int j=0; j<time_; j++){ // Chaque boucle prend environs 1 secondes, le nombre de boucle est donc le temps en secondes
        this_thread::sleep_for(chrono::milliseconds(1000)); // Toutes les 2 secondes on récupère les données des capteurs qu'on envoie au Server
        server.updateTemp(capt_temperature.getData());
        server.updateHumidity(capt_humidity.getData());
        server.updateLight(capt_light.getData());
        server.updatePression(capt_pression.getData());
    }

    //La simulation est finie
    capt_humidity.endSimulation(); // On arrète la simulation des capteurs
    capt_light.endSimulation();
    capt_pression.endSimulation();
    capt_temperature.endSimulation();
    server.endSimulation(); // Et la simulation du server

    thread_temp.join(); // On suprime les thread
    thread_hum.join();
    thread_lig.join();
    thread_pres.join();
    thread_serv.join();

}