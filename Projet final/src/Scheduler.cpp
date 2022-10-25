/*!
 * @author  Cuenot Benoit  
 * @file    Scheduler.cpp
 * @date    25/10/2022  
 * @brief   Cette classe est le Scheduler.cpp du projet, elle est initialisée dans le main et 
 *          lie les class Sensor et Server par composition. Le Scheduler réceptionne les données 
 *          des 4 capteurs à une fréquence définie et les envoie ensuite au Server.      
 */


#include <iostream>
#include <string.h>
#include "../include/Scheduler.hpp"
using namespace std;

Scheduler :: Scheduler()
{
        m_Horloge = 0;
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
        m_Horloge = objScheduler_p.m_Horloge;
}

const void Scheduler :: ChoixUtilisateur() /*!< Utilisateur à le choix au début du programme d'activer la console et le log*/
{
        char ChoixUtilisateur;
        cout << "Le programme va bientot commencer." << endl;
        cout << "Souhaitez vous activer la console ? Y/N : " << endl;
        cin >> ChoixUtilisateur ;
        if(ChoixUtilisateur != 'y' && ChoixUtilisateur != 'Y')
        {
                m_MyServer.SetConsole(false); /*!< Appele méthode du Server pour désactivée la console*/
        }
        cout << "Souhaitez vous enregistrer les donnees dans des logs ? Y/N : " << endl;
        cin >> ChoixUtilisateur ;
        if(ChoixUtilisateur != 'y' && ChoixUtilisateur != 'Y')
        {
                m_MyServer.SetLog(false); /*!< Appele méthode du Server pour désactivée la log*/
        }
        cout << "Le programme commence." << endl;     
        Sleep(1000);
}

void Scheduler :: HorlogeInterne()
{
        Sleep(1000);
        m_Horloge ++; /*Incrémentation de l'horloge interne*/
        cout << endl << "Temps ecoulee : " << m_Horloge << " sec" << endl;        
}

void Scheduler :: RecupAndSendData() /*!< Fonction principal du Scheduler*/
{
        if(m_Horloge % 1 == 0) 
        {
                float valeurTemperature = m_MyTemperature.getData(); /*!< Toutes les secondes*/
                m_MyServer.consolWrite(valeurTemperature);
                m_MyServer.fileWrite(valeurTemperature, "../logs/logTemperature.txt"); /*!< Renvoie la valeur du capteur ainsi que le fichier correspondant pour le log*/
        }
        if(m_Horloge % 2 == 0)
        {
                float valeurHumidity = m_MyHumidity.getData(); /*!< Toutes les 2 secondes*/
                m_MyServer.consolWrite(valeurHumidity);
                m_MyServer.fileWrite(valeurHumidity, "../logs/logHumidite.txt");
        }
        if(m_Horloge % 3 == 0)
        {
                unsigned int valeurPression = m_MyPression.getData(); /*!< Toutes les 3 secondes*/
                m_MyServer.consolWrite(valeurPression);
                m_MyServer.fileWrite(valeurPression, "../logs/logPression.txt");
        }
        if(m_Horloge % 4 == 0)
        {
                bool valeurLight = m_MyLight.getData(); /*!< Toutes les 4 secondes*/
                m_MyServer.consolWrite(valeurLight);
                m_MyServer.fileWrite(valeurLight, "../logs/logLight.txt");
        }      
}