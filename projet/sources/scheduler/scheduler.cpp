//
// Created by rayan on 05/10/2022.
//
#include "scheduler.h"



void Scheduler::QuestionAffichage() {
    int consoleActivation;
    int logActivation;
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

    time.push_back(Time(e_humidity, 1000));
    time.push_back(Time(e_light, 1000));
    time.push_back(Time(e_temperature, 1000));
    time.push_back(Time(e_pressure, 1000));



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
