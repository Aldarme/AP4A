/**
 * @author Planchin Arnaud
 * @file Scheduler.cpp
 * @date 03/10/2022
 * @brief Définition des méthodes de la classe Scheduler
 */

#include "Scheduler.hpp"
#include <iostream>
#ifdef _WIN32
    #include <Windows.h>
#else
    #include <unistd.h>
#endif
using namespace std;

Scheduler Scheduler::getAll(){

    Temperature temp;                                       // Initialisation d'un capteur Temperature et initialisation de ses attributs
    temp.data = 20;
    temp.min = 15;
    temp.max = 25;

    Humidity hum;                                           // Initialisation d'un capteur Humidity et initialisation de ses attributs
    hum.data = 40;
    hum.min = 25;
    hum.max = 50;

    Pression pres;                                          // Initialisation d'un capteur Pression et initialisation de ses attributs
    pres.data = 100;
    pres.min = 90;
    pres.max = 105;

    Light lum;                                              // Initialisation d'un capteur Light et initialisation de ses attributs
    lum.data = 1;
    lum.min = 0;
    lum.max = 1;

    temp.aleaGenVal(temp.min,temp.max);                     // Génération aléatoire des valeurs de chaque capteurs
    hum.aleaGenVal(hum.min,hum.max);
    pres.aleaGenVal(pres.min,pres.max);
    lum.aleaGenVal(lum.min,lum.max);

    scheduler_Pack.temperature.data = temp.GetData();       // Mise en paquet des données générées 
    scheduler_Pack.humidite.data = hum.GetData();
    scheduler_Pack.lumiere.data = lum.GetData();
    scheduler_Pack.pression.data = pres.GetData();

     
    return *this;
}  


void Scheduler::serverSendData(Server& serv,int temps){

    if ((temps%3) == 0){
        serv.server_Pack.lumiere.data = scheduler_Pack.lumiere.data;  
    }
    if ((temps%2) == 0){
        serv.server_Pack.temperature.data = scheduler_Pack.temperature.data;
        serv.server_Pack.humidite.data = scheduler_Pack.humidite.data;
    }
    if ((temps%1) == 0){
        serv.server_Pack.pression.data = scheduler_Pack.pression.data;
    }

}


void Scheduler::wait(int pause_secondes){

    Sleep(pause_secondes*1000);

}