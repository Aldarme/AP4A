/**
 *@author Lola ROQUILLON 
 *@file Scheduler.cpp
 *@date 28/09/2022
 *@brief Cette classe synchronise les données des capteurs et les envois au serveur à intervalle régulier
 */

#include "Scheduler.hpp"
#include <iostream>
#include <Windows.h>
using namespace std;

Scheduler::Scheduler() //constructeur par default
{
    m_mode=0;
    m_duree=0;                
    m_comptT=0;
    m_comptH=0;
    m_comptP=0;
    m_comptL=0;
    m_comptS=0;
}

Scheduler::Scheduler(const Scheduler& scheduler_p)  //constructeur par recopie
{
    m_mode=scheduler_p.m_mode;
    m_duree=scheduler_p.m_duree;                
    m_comptT=scheduler_p.m_comptT;
    m_comptH=scheduler_p.m_comptH;
    m_comptP=scheduler_p.m_comptP;
    m_comptL=scheduler_p.m_comptL;
    m_comptS=scheduler_p.m_comptS;
}



void Scheduler::ScheStart()
{
    do  //Demande de la methode d'affichage/sauvegarde à adopter
    {
        cout <<"Voulez-vous afficher les donnees dans la console et les sauvegarder dans des fichiers? " <<endl <<"Veuillez tapez le numero correspondant a votre demande" <<endl;
        cout <<"Afficher: 1" <<endl <<"Sauvegarder: 2" <<endl <<"Les deux modes: 3" <<endl <<"Ni l'un ni l'autre: 4 " <<endl <<endl ;
        cin >> m_mode;
        cout <<endl;
        if (m_mode<1 || m_mode>4 ) //message d'erreur si la valeur rentrée ne correspond pas à une valeur acceptable pour un mode 
        {
            cout <<"ERREUR! veuillez entrer un chiffre coherant" <<endl;
            cin.clear();
            cin.ignore(255, '\n');
        }  
    }while(m_mode<1 || m_mode>4);

    do  //Demande de la duree de la simulation en seconde
    {
        cout <<"Combien de temps voulez vous que la simulation dure? (en seconde)"<<endl;
        cin >> m_duree;
        cout <<endl;
        if (m_duree<0) //message d'erreur si la valeur rentrée ne correspond pas à une durée de simulation acceptable 
        {
            cout <<"ERREUR! veuillez entrer un chiffre coherant" <<endl;
            cin.clear();
            cin.ignore(255, '\n');
        }
    }while(m_duree<0);
    monTimer(m_duree);    //appel de la fonction monTimer qui génére et envoyer les valeurs des capteurs au server
}

void Scheduler::monTimer(int duree_p)
{   
    //pour le temps de la simulation faire
    for (int i=-1; i<duree_p; i++)
    {
        //genere les valeurs des capteurs à differentes frequences
        if (m_comptT>1)
        {
            sac.s_temp=std::to_string(m_SensorTemp.DataTemperature());
            m_comptT=0;
        }
        if (m_comptH>2)
        {
            sac.s_hum=std::to_string(m_SensorHum.DataHumidity());
            m_comptH=0;
        }
        if (m_comptP>4)
        {
            sac.s_press=std::to_string(m_SensorPress.DataPression());
            m_comptP=0;
        }
        if (m_comptL>5)
        {
            sac.s_light=std::to_string(m_SensorLight.DataLight());
            m_comptL=0;
        }
        
        //envoi des données générées au serveur toutes les 8 secondes
        if (m_comptS>7)
        {
            switch (m_mode)
            {
                case 1: 
                {
                    monServer.consolWrite(sac); //affiche les données dans la console
                }
                break;

                case 2:
                {
                    monServer.fileWrite(sac); //enregistre les données dans des fichiers
                }
                break;
                
                case 3: 
                {
                    monServer.consolWrite(sac);
                    monServer.fileWrite(sac);
                }
                break;

                default:
                {
                    
                }
                break; 
            } 
            m_comptS=0;
        }
        m_comptH++;     //avance tous les compteurs de 1
        m_comptL++;
        m_comptP++;
        m_comptS++;
        m_comptT++;
        Sleep(1000);    //attente de 1 seconde
    }
}