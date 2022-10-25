/*!
 * @author  Cuenot Benoit  
 * @file    Server.cpp
 * @date    25/10/2022  
 * @brief   Cette classe est le Server.cpp du projet, elle sert à récuperer les données des 4 capteurs 
 *          afin de les afficher ou non dans le terminal ou sur les fichiers de logs
 */

#include <iostream>
#include <string.h>
#include "../include/Server.hpp"

using namespace std;

Server :: Server()
{
        m_booleenAffichage = true;
        m_booleenLog = true;
}

Server :: Server(bool booleenAffichage_p, bool booleenLog_p)
{
        m_booleenAffichage = booleenAffichage_p;
        m_booleenLog = booleenLog_p;
}

Server :: Server(const Server& objServer_p)
{
        m_booleenAffichage = objServer_p.m_booleenAffichage;
        m_booleenLog = objServer_p.m_booleenLog;
}

Server :: ~Server()
{

}

void Server :: SetConsole(bool booleenAffichage_p)
{
        m_booleenAffichage = booleenAffichage_p;
}

void Server ::SetLog(bool booleenLog_p)
{
        m_booleenLog = booleenLog_p;
}

template <typename T>
void Server :: consolWrite(T donneecapteur_p) /*!< Affichage à la console des données de capteurs ; dépend de la valeur du booléen en paramètre*/
{
        if(m_booleenAffichage) /*!< Si affichage activée*/
        {
                if(typeid(donneecapteur_p) == typeid(float) && donneecapteur_p < 0) /*!< Si la donnée est un float et en dessous de 0, c'est donc la température*/
                {
                        cout << "Temperature : " << donneecapteur_p << " degres" << endl;
                }
                else if(typeid(donneecapteur_p) == typeid(float) && donneecapteur_p >= 0) /*!< Si la donnée est un float et au dessus de 0, c'est donc l'humidité*/
                {
                        cout << "Humidite : " << donneecapteur_p << " %" << endl;
                }
                else if(typeid(donneecapteur_p) == typeid(unsigned int)) 
                {
                        cout << "Pression : " << donneecapteur_p << " hPa" << endl;
                }
                else if(typeid(donneecapteur_p) == typeid(bool))
                {
                        cout << "Light : " << donneecapteur_p << " lux" << endl;
                }           
        }        
}

template <typename T>
void Server :: fileWrite(T donneecapteur_p, string nomFichier_p) /*!< Ecriture dans les fichiers logs des données de capteurs ; dépend de la valeur du booléen en paramètre*/
{
        if(m_booleenLog)
        {       
                ofstream file(nomFichier_p, ios :: app); /*!< Ouverture des fichiers correspondants*/
                if(file)
                {       
                        if(nomFichier_p == "../logs/logTemperature.txt")
                        {
                                file << "Temperature : " << donneecapteur_p << " degré" << endl;
                                file.close();
                        }
                        else if(nomFichier_p == "../logs/logHumidite.txt")
                        {
                                file << "Humidité : " << donneecapteur_p << " %" << endl;
                                file.close();
                        }
                        else if(nomFichier_p == "../logs/logPression.txt")
                        {
                                file << "Pression : "<< donneecapteur_p << " hPa" << endl;
                                file.close();
                        }
                        else if(nomFichier_p == "../logs/logLight.txt")
                        {
                                file << "Lumière : " << donneecapteur_p << " lux" <<endl;
                                file.close();
                        }
                }
        }      
}                  