/**
 * @author lois roger
 * @file Sensor.hpp
 * @date 05/10/2022
 * @brief  recupère les données des capteurs toutes les 5 secondes et les envoient au server
 */

#include "Scheduler.hpp"
#include "Server.hpp"
#include <iostream>
#include <unistd.h>


void Scheduler::ecriture(int attente)  // fonction qui écrit les donées dans le fichier attribuée et/ou dans la console
{
    int ecrire = 0;
    int affichage = 0;
    std::cout<<"tapez 1 pour afficher les valeur dans la console ou 0 pour ne pas les afficher"<<std::endl;
    std::cin>>affichage;
    std::cin.ignore();
    std::cout<<"tapez 1 pour ecrire les valeurs dans les logs ou 0 pour ne pas les ecrire"<<std::endl;
    std::cin>>ecrire;
    std::cin.ignore();
    int temps = 0;
    while(temps<attente)
    {
        float valeurt;
        float valeurh;
        int valeurp;
        int valeurl;
        
        if(temps%5 ==0)
        {
            valeurt = m_temperature.getData(15,40);
            if(affichage == 1)
            {
                m_serv.consolwrite(valeurt, valeurp, valeurl, valeurh, "temperature");
            }
            
            if(ecrire ==1)
            {
                m_serv.filewrite(valeurt, valeurp, valeurl, valeurh, "temperaturelog.txt");
            }
        }
        
        if(temps%10 ==0)
        {
            valeurh = m_humidity.getData(0, 100);
            if(affichage == 1)
            {
                m_serv.consolwrite(valeurt, valeurp, valeurl, valeurh, "humidity");
            }
            
            if(ecrire ==1)
            {
                m_serv.filewrite(valeurt, valeurp, valeurl, valeurh, "humidity.txt");
            }
        }

        if(temps% 15== 0)
        {
            valeurp = m_pression.getData(1000, 100);
            if(affichage == 1)
            {
                m_serv.consolwrite(valeurt, valeurp, valeurl, valeurh, "pression");
            }
            
            if(ecrire ==1)
            {
                m_serv.filewrite(valeurt, valeurp, valeurl, valeurh, "pressionlog.txt");
            }
        }
        
        if(temps%20 == 0)
        {
            valeurl = m_light.getData(0, 1);
            if(affichage == 1)
            {
                m_serv.consolwrite(valeurt, valeurp, valeurl, valeurh, "light");
            }
            
            if(ecrire ==1)
            {
                m_serv.filewrite(valeurt, valeurp, valeurl, valeurh, "lightlog.txt");
            }
        }
        
        sleep(5);
        temps =temps+5;        
    }
}