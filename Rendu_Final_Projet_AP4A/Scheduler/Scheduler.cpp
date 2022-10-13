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
    /** On utilise ref() pour que les changements des valeurs des sensors s'effectuent aussi ici
     * On ne peut pas passer une référence directement à un thread (&) car std::thread les copiera/déplacera. À la place il faut utiliser std::ref()
    **/
    thread thread_hum(&Humidity::startSimulation, ref(capt_humidity)); 
    thread thread_lig(&Light::startSimulation, ref(capt_light)); 
    thread thread_pres(&Pression::startSimulation, ref(capt_pression)); 

    //On annonce au server s'il devra afficher en console et écrire dans le log
    server.updateDoLog(doLog_);
    server.updateDoPrintConsole(doPrintConsole_);
    thread thread_serv(&Server::startSimulation, ref(server)); // On créer le thread pour le server

    for(int j=0; j<time_; j++){ // Chaque boucle prend environs 1 secondes, le nombre de boucle est donc le temps en secondes
        this_thread::sleep_for(chrono::milliseconds(1000)); //On attend une seconde
        //On récupère les données avec getData et on les modifies dans le serveur en même temps avec update
        if(j%1 == 0){
            server.updateTemp(capt_temperature.getData()); // Toutes les secondes
}
        if(j%2 == 0){
            server.updateHumidity(capt_humidity.getData()); // Toutes les 2 secondes
        }
        if(j%3 == 0){
            server.updateLight(capt_light.getData()); // Toutes les 3 secondes
        }
        if(j%4 == 0){
            server.updatePression(capt_pression.getData()); // Toutes les 4 secondes
        }

    }

    //La simulation est finie
    capt_humidity.endSimulation(); // On arrète la simulation des capteurs
    capt_light.endSimulation();
    capt_pression.endSimulation();
    capt_temperature.endSimulation();
    server.endSimulation(); // Et la simulation du server

    thread_temp.join(); // Permet de bien attendre la fin des threads avant d'arreter le thread principal 
    thread_hum.join();
    thread_lig.join();
    thread_pres.join();
    thread_serv.join();

}