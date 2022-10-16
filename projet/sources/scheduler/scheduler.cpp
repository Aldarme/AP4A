//
// Created by rayan on 05/10/2022.
//
#include "scheduler.h"



void Scheduler::QuestionAffichage() {
    int consoleActivation;
    int logActivation;
    std::cout << "Bienvenue\n" << std::endl;
    std::cout << "Voulez vous afficher les donnees ? [1/0] :" << std::endl;
    std::cin >> consoleActivation;
    while(consoleActivation>1 or consoleActivation<0){
        std::cout << "TAPEZ 1 OU 0 Voulez vous afficher les donnees ? [1/0] :" << std::endl;
        std::cin >> consoleActivation;

    }
    std::cout << "Voulez vous stocker les donnees dans les log ? [1/0] :" << std::endl;
    std::cin >> logActivation;
    while(logActivation>1 or logActivation<0){
        std::cout << "TAPEZ 1 OU 0 Voulez vous stocker les donnees dans les log ? [1/0] :" << std::endl;
        std::cin >> logActivation;

    }
    if(consoleActivation==0)
    {
        server.affichageConsole();
    }
    if(logActivation==0){
        server.ecritureLog();
    }
    if(consoleActivation==0 and logActivation==0){
        exit(EXIT_SUCCESS);
    }
}

Scheduler::Scheduler()
{
    QuestionAffichage();

    listSensors.push_back(&this->humiditySensor);
    listSensors.push_back(&this->lightSensor);
    listSensors.push_back(&this->temperatureSensor);
    listSensors.push_back(&this->pressureSensor);

    std::cout << "Quelle duree (en secondes) entre chaque valeur pour la temperature ? " << std::endl;
    int sectemp;
    std::cin >> sectemp;
    sectemp=sectemp*1000;
    std::cout << "Quelle duree (en secondes) entre chaque valeur pour l'humidite ? " << std::endl;
    int sechum;
    std::cin >> sechum;
    sechum=sechum*1000;
    std::cout << "Quelle duree (en secondes) entre chaque valeur pour la lumiere ? " << std::endl;
    int seclum;
    std::cin >> seclum;
    seclum=seclum*1000;
    std::cout << "Quelle duree (en secondes) entre chaque valeur pour la pression ? " << std::endl;
    int secpre;
    std::cin >> secpre;
    secpre=secpre*1000;


    time.push_back(Time(e_humidity, sechum));
    time.push_back(Time(e_light, seclum));
    time.push_back(Time(e_temperature, sectemp));
    time.push_back(Time(e_pressure, secpre));



    while (true)
    {
        for (int i = 0; i < (int)this->time.size(); ++i)
        {
            if (time[i].checkTime())
            {
                for (int j = 0; j < (int)listSensors.size(); j++)
                {
                    const SensorData& data = listSensors[j]->getData();
                    if (data.TypeSensor == time[i].m_TypeSensor)
                    {
                        server << listSensors[j]->getData();


                    }
                }
            }
        }
    }
};


Scheduler::~Scheduler() {}


