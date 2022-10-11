/*!
 * @author  Cuenot Benoit  
 * @file    Scheduler.hpp
 * @date    11/10/2022  
 * @brief   Cette classe est le Scheduler.hpp du projet, elle est initialisée dans le main et 
 *          lie les class Sensor et Server par composition. Le Scheduler réceptionne les données 
 *          des 4 capteurs à une fréquence définie et les envoie ensuite au Server.      
 */

#ifndef SCHEDULER_HPP_INCLUDED
#define SCHEDULER_HPP_INCLUDED

#include "Sensor.hpp"
#include "Server.hpp"
#include <windows.h>


class Scheduler{

private:

        Temperature m_MyTemperature;
        Humidity m_MyHumidity;
        Light m_MyLight;
        Pression m_MyPression;

        Server m_MyServer;
     
public:

        
        Scheduler();
        Scheduler(const Scheduler& objScheduler_p);
        ~Scheduler();

        void RecupData();       /*!< Cette méthode permet la récupération des valeurs de capteurs depuis les différents Sensor*/

        void EnvoyerServer(bool booleenAffichage_p, bool booleenLog_p);     /*!< Permet d'envoyer les valeurs de capteurs au Server. Les arguments détermine l'affichage Console et l'écriture des valeurs dans les logs*/

        void Attendre(int TempsMs_p);  /*!< Permet de définir un fréquence d'envoyer des valeurs. L'argument permet de varier cette fréquence*/

        const void InformationsUtilisateur() ;  /*!< Cette méthode donne quelques informations sur le programme à l'utilisateur en début d'éxécution*/
};

#endif // SCHEDULER_HPP_INCLUDED