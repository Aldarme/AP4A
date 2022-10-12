#include "Scheduler.hpp"
//scheduler.cpp

#include <iostream>

#include <fstream>
#include <ctime>
#include <windows.h>
//#include <unistd.h>


using namespace std;

Scheduler::Scheduler() : m_temperature(), m_humidity(), m_light(), m_sound(), m_server(), m_dureeTotale(), m_delta() {};

Scheduler::Scheduler(const Scheduler& scheduler_p) : m_temperature(scheduler_p.m_temperature), m_humidity(scheduler_p.m_humidity), m_light(scheduler_p.m_light), m_sound(scheduler_p.m_sound), m_server(scheduler_p.m_server), m_dureeTotale(scheduler_p.m_dureeTotale), m_delta(scheduler_p.m_delta) {};

Scheduler::~Scheduler() = default;

Scheduler& Scheduler::operator=(const Scheduler& scheduler)
{
    this->m_temperature = scheduler.m_temperature;
    this->m_humidity = scheduler.m_humidity;
    this->m_light = scheduler.m_light;
    this->m_sound = scheduler.m_sound;
    this->m_server = scheduler.m_server;
    this->m_dureeTotale = scheduler.m_dureeTotale;
    this->m_delta = scheduler.m_delta;

    return *this;
}

void Scheduler::launchSimulation()
{
    this->m_temperature.setMinMax(0, 50);
    this->m_humidity.setMinMax(0, 50);
    this->m_light.setMinMax(0, 50);
    this->m_sound.setMinMax(0, 50);

    bool rep;

    while (this->m_dureeTotale <= 0)
    {
        cout << "Nouvelle simulation" << endl;
        cout << "Durée de la simulation (en sec) : " << endl;
        cin >> this->m_dureeTotale;
    }


    while (this->m_delta <= 0)
    {
        cout << " Fréquence de récupération des données (en sec) " << endl;
        cin >> this->m_delta;
    }


    while (rep != 1 && rep != 0)
    {
        cout << "Voulez-vous visualiser les donnees dans la console ? (1 = oui // 0 = non)" << endl;
        cin >> rep;
    }

    this->m_server.setConsolActivation(rep);

    while (rep != 1 && rep != 0)
    {
        cout << "Souhaitez vous stocker les donnees dans le fichier log ? (1 = oui // 0 = non)" << endl;
        cin >> rep;
    }
    this->m_server.setLogActivation(rep);

    cout << " Début de la simulation " << endl;

    if (this->m_server.getLogActivation())
    {
        ofstream file("log.txt", ofstream::out | ofstream::trunc);
        file.close();
    }


    while (this->m_dureeTotale - this->m_delta >= 0)
    {
        genRandom(); //On donne des valeurs aléatoires à nos sensors
        sendValues(); //Nous envoyons les données au server
        //sleep(this->m_delta); //Nous attendons la periode de temps indiqué par l'utilisateur
        this->m_dureeTotale = this->m_dureeTotale - this->m_delta; //mettre à jour le chrono à la fin de la boucle
    }
}

void Scheduler::genRandom()
{
    this->m_temperature.aleaGenVal();
    this->m_humidity.aleaGenVal();
    this->m_light.aleaGenVal();
    this->m_sound.aleaGenVal();

}

void Scheduler::sendValues()
{
    if (this->m_server.getConsolActivation())
    {
        this->m_server.consolWrite(this->m_temperature.getValue(), this->m_humidity.getValue(), this->m_light.getValue(), this->m_sound.getValue());
    }
    if (this->m_server.getLogActivation()) {
        this->m_server.fileWrite(this->m_temperature.getValue(), this->m_humidity.getValue(), this->m_light.getValue(), this->m_sound.getValue());
    }
}
