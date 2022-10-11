/*!
 * @author  Cuenot Benoit  
 * @file    Server.cpp
 * @date    11/10/2022  
 * @brief   Cette classe est le Server.cpp du projet, elle sert à récuperer les données des 4 capteurs 
 *          afin de les afficher ou non dans le terminal ou sur les fichiers de logs
 */

#include <iostream>
#include <string.h>
#include "Server.hpp"

using namespace std;


Server :: Server()
{
        m_donneeTemperature = 0;
        m_donneeHumidity = 0;
        m_donneePression = 0;
        m_donneeLight = 0;
}
Server :: Server(int donneeTemperature_p, int donneeHumidity_p, int donneePression_p, int donneeLight_p){

        m_donneeTemperature = donneeTemperature_p;
        m_donneeHumidity = donneeHumidity_p;
        m_donneePression = donneePression_p;
        m_donneeLight = donneeLight_p;
}

Server :: Server(const Server& objServer_p)
{
        m_donneeTemperature = objServer_p.m_donneeTemperature;
        m_donneeHumidity = objServer_p.m_donneeHumidity;
        m_donneePression = objServer_p.m_donneePression;
        m_donneeLight = objServer_p.m_donneeLight;
}

Server :: ~Server()
{

}


void Server :: dataRcv(int valeurTemperature_p, int valeurHumidity_p, int valeurPression_p, int valeurLight_p)  /*!< Récupération des valeurs de capteurs depuis le Scheduler*/
{
        m_donneeTemperature = valeurTemperature_p;
        m_donneeHumidity = valeurHumidity_p;
        m_donneePression = valeurPression_p;
        m_donneeLight = valeurLight_p;
}

void Server :: consolWrite(bool booleenAffichage_p) /*!< Affichage à la console des données de capteurs ; dépend de la valeur du booléen en paramètre*/
{
        if(booleenAffichage_p)
        {
                cout << "Temperature : " << m_donneeTemperature << " degres" << endl;
                cout << "Humidite : " << m_donneeHumidity << " %" << endl;
                cout << "Pression : " << m_donneePression << " hPa" << endl;
                cout << "Light : " << m_donneeLight << " lux" << endl;
        }
        else
        {
                cout << "Terminal desactive" << endl;
        }
}

void Server :: fileWrite(bool booleenLog_p) /*!< Ecriture dans les fichiers logs des données de capteurs ; dépend de la valeur du booléen en paramètre*/
{
        if(booleenLog_p)
        {
                        // Ouverture des fichiers 
                ofstream logTemperature("logTemperature.txt", ios:: app);
                ofstream logHumidite("logHumidite.txt", ios::app);
                ofstream logPression("logPression.txt", ios::app); 
                ofstream logLight("logLight.txt", ios::app);

                        // Ecriture dans les fichiers
                if(logTemperature && logHumidite && logPression && logLight)
                {
                        logTemperature << "Temperature : "<< m_donneeTemperature << " degrés"<< endl;
                        logHumidite << "Humidité : " << m_donneeHumidity << " %"<< endl;
                        logPression << "Pression : "<< m_donneePression << " hPa" << endl;
                        logLight << "Lumière : " << m_donneeLight << " lux" <<endl;
                }
                else
                {
                        cout << "Erreur, un des fichiers de s'est pas ouvert" << endl;
                }
        }
        else
        {
                cout << "Ecriture dans les fichiers desactivees" << endl;
        }
}