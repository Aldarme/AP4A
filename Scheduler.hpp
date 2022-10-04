/*      author:TRABOULSI Rawan
        *SCHEDULER
        *Créé le 19/09/2020 */
#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP
#include "Server.hpp"
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

        Sensor m_Stemperature;
        Sensor m_Shumidity;
        Sensor m_Slight;
        Sensor m_Spressure;

        //La forme canonique
        Scheduler();//constructeur par defaut
        Scheduler(const Scheduler &autre);//constructeur de recopie
        Scheduler &operator=(const Scheduler &);//operateur d'affectation
        virtual~Scheduler();//destructeur

        //Les Méthodes
        int transmetTemperature();
        int transmetPressure();
        int transmetHumidity();
        int transmetBrightness();

        void transmetData1(Server server_p,int frequency_p,int temps_p);
};

#endif //SCHEDULER_H
