/*      author:TRABOULSI Rawan
        *SCHEDULER
        *Créé le 09/10/2020 */
#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP
#include "Server.hpp"
#include "Temperature.hpp"
#include "Pressure.hpp"
#include "Humidity.hpp"
#include "Brightness.hpp"
#include <string>

class Scheduler{
        public:
        Server m_Server;

        Temperature m_Temp;
        Humidity m_Humidity;
        Brightness m_Brightness;
        Pressure m_Pressure;

        /*Sensor m_Stemperature;
        Sensor m_Shumidity;
        Sensor m_Slight;
        Sensor m_Spressure;*/

        //La forme canonique
        Scheduler();//constructeur par defaut
        Scheduler(const Scheduler &autre);//constructeur de recopie
        Scheduler &operator=(const Scheduler &);//operateur d'affectation
        virtual~Scheduler();//destructeur
        //transmetDATA fct finale pour le transmet des valeurs captées par chaque capteur à des intervalles de temps différentes  
        void transmetDATA(Server serverfinal_p,int temps_p,int temps_temperature_p,int temps_pressure_p,int temps_humidity_p,int temps_brightness_p);
};

#endif //SCHEDULER_H
