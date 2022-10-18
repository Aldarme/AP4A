/**
 * @author Cameron ROCHEBILLARD
 * @file Scheduler.cpp
 * @date 4/10/2022
 * @brief permet de réunir et envoyer les données des capteurs
 */

 //
 //Define guards 
 #ifndef SCHEDULER_H
 #define SCHEDULER_H
 
#include "Temperature.hpp"
#include "Humidite.hpp"
#include "Lumiere.hpp"
#include "Pression.hpp"
#include "Server.hpp"
#include "Sensor.hpp"

int Temp;
int Hum;
int Lig;
int Press;

int i;

class Scheduler
{
    public:
        void scheduler()
        {
            Temperature T;
            Humidity H;
            Light L;
            Pression P;


            Temp =T.getData(T.T_max, T.T_min);
            Hum = H.getData(H.H_max, H.H_min);
            Lig = L.getData(L.L_max, L.L_min);
            Press = P.getData(P.P_max, P.P_min);

            Server::consolWrite(Temp);
            Server::fileWrite(Temp,0);

            if (i%2 == 0)
            {
                Server::consolWrite(Hum);
                Server::fileWrite(Hum,1); 
            }

            else if (i%5 == 0)
            {
                Server::consolWrite(Lig);
                Server::fileWrite(Lig,2);
            }

            else if (i%3 == 0)
            {
                Server::consolWrite(Press);
                Server::fileWrite(Press,3);
            }

        }
};




 #endif //SCHEDULER_H