/**
 * @author Planchin Arnaud
 * @file Scheduler.cpp
 * @date 03/10/2022
 * @brief Définition de chaque méthode de Scheduler
 */

#include "Scheduler.hpp"

Scheduler Scheduler::getAll(){

    Temperature temp;
    Humidity hum;
    Pression pres;
    Light lum;

    temp.genAlea();
    hum.genAlea();
    pres.genAlea();
    lum.genAlea();

    scheduler_Pack.temperature.data = temp.GetData();
    scheduler_Pack.humidite.data = hum.GetData();
    scheduler_Pack.lumiere.data = lum.GetData();
    scheduler_Pack.pression.data = pres.GetData();
    
    return *this;
}  

void Scheduler::serverSendData(Server& serv){

    serv.server_Pack = scheduler_Pack;

}

void Scheduler::wait(){

    int pause_secondes = 1;
    Sleep(pause_secondes*1000);

}