/**
 * @author A.BARTHELME
 * @file scheduler.cpp
 * @date 12/10/2022
 * @brief Fichier du scheduler, incluant les fonctions de la classe Scheduler
 * @version Intermediaire 
*/



#include<iostream>
#include<string>
#include<ctime>
#include <unistd.h>
#include "Scheduler.hpp"
#include "AllSensor.hpp"
#include "Serveur.hpp"
#include "Paquet.hpp"



using namespace std;

Scheduler::Scheduler()
{
    cout << "Scheduler created" << endl;
    Temperature T1("CapteurTemp1");
    Humidite H1("CapteurHumi1");
    Pression PR1("CapteurPress1");
    Luminosite L1("CapteurLum1");
    
}

Scheduler::Scheduler(Temperature T1, Humidite H1, Pression PR1, Luminosite L1)
{
    cout << "Scheduler created" << endl;
    Temperature T = T1;
    Humidite H = H1;
    Pression PR = PR1;
    Luminosite L = L1;
        
}

void Scheduler::StartScheduler()
{
    cout << "Scheduler started" << endl;
    Serveur srv1("Serveur1");
    //srv1.CleanFile();
    printf("voulez vous afficher dans la console ? (y/n) : ");
    char c;
    cin >> c;
    for (int i = 0; i < 5; i++)
    {
        Paquet P1(T1.GetTemperature(),"CapteurTtemp1","Celsius");
        Paquet P2(H1.GetHumidite(),"CapteurHumi1","%");
        Paquet P3(PR1.GetPression(),"CapteurPress1","hPa");
        Paquet P4(L1.GetLuminosite(),"CapteurLum1","Lux");
        // Paquet P1, P2, P3, P4 = GetAll();

    if (c == 'y'){
        srv1.consoleWriter(P1);
        srv1.consoleWriter(P2);
        srv1.consoleWriter(P3);
        srv1.consoleWriter(P4);
    }
    else if (c == 'n'){
        cout << "Donnees en cours d ecrire dans les fichiers logs" << endl;
    }
    else{
        cout << "Erreur de saisie" << endl;
    }
        srv1.fileWriter(P1);
        srv1.fileWriter(P2);
        srv1.fileWriter(P3);
        srv1.fileWriter(P4);
        sleep(1);
    }
}

//Paquet Scheduler::GetAll() {}
