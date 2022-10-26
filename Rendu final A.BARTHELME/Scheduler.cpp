/**
 * @author A.BARTHELME
 * @file Scheduler.cpp
 * @date 26/10/2022
 * @brief Fichier du scheduler, incluant les fonctions de la classe Scheduler
 * @version Finale 
 * @details Ce fichier est le principale, il coordonne les autres fichiers et permet de lancer le programme
 * @bug Risque de problème avec la fonction "sleep" qui n'est pas compatible avec tous les OS
 *  
*/

// ATTENTION : programme developpé et fonctionnel sous Windows 11 avec VScode et make installé sur windows et en WSL2 sur Ubuntu
// la fonction "sleep" peut causer des problemes sur d'autres PC.

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
    cout << "Scheduler created " << endl;
    Temperature T1("CapteurTemp1");
    Humidite H1("CapteurHumi1");
    Pression PR1("CapteurPress1");
    Luminosite L1("CapteurLum1");
    
}

Scheduler::Scheduler(Temperature T1, Humidite H1, Pression PR1, Luminosite L1)
{
    cout << "Scheduler created " << endl;
    Temperature T = T1;
    Humidite H = H1;
    Pression PR = PR1;
    Luminosite L = L1;
        
}

void Scheduler::StartScheduler()
{
    cout << "Scheduler started" << endl;
    Serveur srv1("Serveur1");
    cout << "voulez vous afficher dans la console ? (y/n) : " <<endl;
    char c;
    cin >> c;
    while (true)
    {
        cout<<"petit test2"<<endl;
        //Seconde 1 ( Lumiere + Humidite + Lumiere )
        Paquet<int> P1(PR1.GetPression(),"CapteurPress1","hPa",2);
        Paquet<float> P2(H1.GetHumidite(),"CapteurHumi1","%",3);
        Paquet<bool> P3(L1.GetLuminosite(),"CapteurLum1","Lux",4);
        //ecriture dans les logs
        srv1.fileWriter(P1);
        srv1.fileWriter(P2);
        srv1.fileWriter(P3);
        if (c == 'y')
        {
            srv1.consoleWriter(P1);
            srv1.consoleWriter(P3);
            srv1.consoleWriter(P2);
        }
        else
        {
            cout << "ecriture dans les logs" << endl;
        }
        cout<< "sleep 1 seconde, end of S1" << endl;
        cout << "----------------------------------" << endl;
        sleep(1);
        


        //Seconde 2 ( Temperature + PRession )
        Paquet<int> P4(PR1.GetPression(),"CapteurPress1","hPa",2);
        Paquet<float> P5(T1.GetTemperature(),"CapteurTemp","Celsius",1);
        //ecriture dans les logs
        srv1.fileWriter(P5);
        srv1.fileWriter(P4);
        if (c == 'y')
        {
            srv1.consoleWriter(P5);
            srv1.consoleWriter(P4);
        }
        else
        {
            cout << "ecriture dans les logs" << endl;
        }
        cout<< "sleep 1 seconde, end of S2" << endl;
        cout << "----------------------------------" << endl;
        sleep(1);
        


        //seconde 3 (Tous les capteurs)
        Paquet<float> P7(T1.GetTemperature(),"CapteurTemp","Celsius",1);
        Paquet<float> P8(H1.GetHumidite(),"CapteurHumi1","%",3);
        Paquet<int> P9(PR1.GetPression(),"CapteurPress1","hPa",2);
        Paquet<bool> P10(L1.GetLuminosite(),"CapteurLum1","Lux",4);
        if (c == 'y')
        {
            srv1.consoleWriter(P7);
            srv1.consoleWriter(P8);
            srv1.consoleWriter(P9);
            srv1.consoleWriter(P10);
        }
        else
        {
            cout << "ecriture dans les logs" << endl;
        }
        //ecriture dans les logs
        srv1.fileWriter(P7);
        srv1.fileWriter(P8);
        srv1.fileWriter(P9);
        srv1.fileWriter(P10);
        cout<< "sleep 1 seconde, end of S3" << endl;
        cout << "----------------------------------" << endl;

        sleep(1);
               

        //seconde 4 ( Temperature + PRession )
        Paquet<int> P11(PR1.GetPression(),"CapteurPress1","hPa",2);
        Paquet<float> P12(T1.GetTemperature(),"CapteurTemp","Celsius",1);
        //ecriture dans les logs
        srv1.fileWriter(P11);
        srv1.fileWriter(P12);
        if (c == 'y')
        {
            srv1.consoleWriter(P11);
            srv1.consoleWriter(P12);
        }
        else
        {
            cout << "ecriture dans les logs" << endl;
        }
        cout<< "sleep 1 seconde, end of S4" << endl;
        cout << "----------------------------------" << endl;

        sleep(1);


        //seconde 5 (Temperature + Humidite + Lumiere )
        Paquet<float> P13(H1.GetHumidite(),"CapteurHumi1","%",3);
        Paquet<float> P14(T1.GetTemperature(),"CapteurTemp","Celsius",1);
        Paquet<bool> P15(L1.GetLuminosite(),"CapteurLum1","Lux",4);
        //ecriture dans les logs
        srv1.fileWriter(P13);
        srv1.fileWriter(P14);
        srv1.fileWriter(P15);
        if (c == 'y')
        {
            srv1.consoleWriter(P13);
            srv1.consoleWriter(P14);
            srv1.consoleWriter(P15);
        }
        else
        {
            cout << "ecriture dans les logs" << endl;
        }
        cout << "sleeping 1 second, end S5" << endl;
        cout << "-------------------------------------" << endl;

        sleep(1);


/*      s1  s2  s3  s4  s5
        T	T	T	T	T
        H		H		H
	        P	P	P
        L		L		L
*/
        }
}


