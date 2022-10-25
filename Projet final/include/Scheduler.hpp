/*!
 * @author  Cuenot Benoit  
 * @file    Scheduler.hpp
 * @date    25/10/2022  
 * @brief   Cette classe est le Scheduler.hpp du projet, elle est initialisée dans le main et 
 *          lie les class Sensor et Server par composition. Le Scheduler réceptionne les données 
 *          des 4 capteurs à une fréquence définie et les envoie ensuite au Server.      
 */

#ifndef SCHEDULER_HPP_INCLUDED
#define SCHEDULER_HPP_INCLUDED
#include "Sensor.hpp"
#include "Server.hpp"
#include "Temperature.hpp"
#include "Humidity.hpp"
#include "Light.hpp"
#include "Pression.hpp"
#include <windows.h>
#include <typeinfo>
#include <thread>

class Scheduler{

private:

        Temperature<float> m_MyTemperature;
        Humidity<float> m_MyHumidity;
        Light<bool> m_MyLight;
        Pression<unsigned int> m_MyPression;
        Server m_MyServer;

        int m_Horloge; /*!< Cette s'incrémentera chaque secondes et servira d'hormole au programme*/
     
public: 
        
        Scheduler();
        Scheduler(const Scheduler& objScheduler_p);
        ~Scheduler();

        const void ChoixUtilisateur();  /*!< Cette méthode permet à ce que l'utilisateur ai le choix d'activer la console ainsi que le log des données*/
        void HorlogeInterne();  /*!< Permet de définir un fréquence d'envoyer des valeurs. L'argument permet de varier cette fréquence*/
        void RecupAndSendData();      /*!< Cette méthode permet la récupération des valeurs de capteurs depuis les différents Sensor et envoie au Server*/      
};

#endif // SCHEDULER_HPP_INCLUDED