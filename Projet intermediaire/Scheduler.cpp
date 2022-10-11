/*!
 * @author  Cuenot Benoit  
 * @file    Scheduler.cpp
 * @date    11/10/2022  
 * @brief   Cette classe est le Scheduler.cpp du projet, elle est initialisée dans le main et 
 *          lie les class Sensor et Server par composition. Le Scheduler réceptionne les données 
 *          des 4 capteurs à une fréquence définie et les envoie ensuite au Server.      
 */


#include <iostream>
#include <string.h>
#include "Scheduler.hpp"


using namespace std;

Scheduler :: Scheduler()
{

}   

Scheduler :: ~Scheduler()
{

}

Scheduler :: Scheduler(const Scheduler& objScheduler_p)
{
        m_MyLight = objScheduler_p.m_MyLight;
        m_MyPression = objScheduler_p.m_MyPression;
        m_MyTemperature = objScheduler_p.m_MyTemperature;
        m_MyHumidity = objScheduler_p.m_MyHumidity;
}

void Scheduler :: RecupData()
{
        /*!< RecupDate() récupère toute les valeurs des Sensors*/

        m_MyTemperature.getData();
        m_MyHumidity.getData();
        m_MyLight.getData();
        m_MyPression.getData();
}

void Scheduler :: EnvoyerServer(bool booleenAffichage_p, bool booleenLog_p)
{
        /*!< Stockage des valeurs dans des variables locals*/

        int valeurTemperature = m_MyTemperature.ValeurData();
        int valeurHumidity = m_MyHumidity.ValeurData();
        int valeurPression = m_MyPression.ValeurData();
        int valeurLight = m_MyLight.ValeurData();

        m_MyServer.dataRcv(valeurTemperature,valeurHumidity,valeurPression,valeurLight); /*!< Envoie des valeurs de capteurs au Server*/

        m_MyServer.consolWrite(booleenAffichage_p); /*!< Affichage console des valeurs*/

        m_MyServer.fileWrite(booleenLog_p); /*!< Affichage dans les fichiers des valeurs */
} 

void Scheduler :: Attendre(int tempsMs_p)
{
        Sleep(tempsMs_p);
}

const void Scheduler :: InformationsUtilisateur()
{
        cout << "Le programme va bientot commencer." << endl;
        cout << "Les donnees sont echantillonees toutes les 2 secondes" << endl;
        cout << "Pour arreter le programme a tout moment : faites 'ctrl+C' dans le terminal" << endl;
        Sleep(2000);
}