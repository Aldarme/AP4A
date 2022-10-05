/**
 *@author Lola ROQUILLON 
 *@file Scheduler.cpp
 *@date 28/09/2022
 *@brief Cette classe synchronise les donées des capteurs et les envois au serveur à intervalle régulier
 */

#include "Scheduler.hpp"
#include <iostream>
#include <Windows.h>
#include <time.h>
using namespace std;

Scheduler::Scheduler()
{
    //Demande du mode d'enregistrement et/ou d'affichage
    cout <<"Voulez-vous afficher les donnees dans la console et les sauvegarder dans des fichiers? " <<endl <<"Veuillez tapez le numero correspondant a votre demande" <<endl;
    cout <<"Afficher: 1" <<endl <<"Sauvegarder: 2" <<endl <<"Les deux modes: 3" <<endl <<"Ni l'un ni l'autre: 4 " <<endl <<endl ;
    cin >> m_mode;
    cout <<endl;
    monTimer(); 
    
}

Scheduler::~Scheduler()
{  }

void Scheduler::monTimer()
{
    clock_t m_t;    //creation d'un timer
    m_t=clock();    //start
    Sleep(1000); 

    while (m_t!=0)
    {
        //envoi des donées générées au serveur
        monServer.mesDonnee(m_SensorTemp.getData(15,30), m_SensorHum.getData(40,60), m_SensorPress.getData(800,1200), m_SensorLight.getData(0,2));
        switch (m_mode)
        {
            case 1: 
            {
                monServer.consolWrite(); //affiche les données dans la console
            }
            break;

            case 2:
            {
                monServer.fileWrite(); //enregistre les données dans des fichiers
            }
            break;
            
            case 3: 
            {
                monServer.consolWrite();
                monServer.fileWrite();
            }
            break;

            default:
            {
                
            }
            break; 
        }
        Sleep(8000);
    }
}