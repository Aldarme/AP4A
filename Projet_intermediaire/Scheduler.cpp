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
 
#include <Scheduler.hpp>
#include <Server.hpp>
#include <Sensor.hpp>

int Temp;
int Hum;
int Lig;
int Press;

class Scheduler
{
    public:
        void scheduler()
        {
            Server Ser;
            Temperature T;
            Humidity H;
            Light L;
            Pression P;


            Temp =T.getData(T.T_max, T.T_min);
            Hum = H.getData(H.H_max, H.H_min);
            Lig = L.getData(L.L_max, L.L_min);
            Press = P.getData(P.P_max, P.P_min);

            Ser.consolWrite(Temp);
            Ser.fileWrite(Temp,0);

            Ser.consolWrite(Hum);
            Ser.fileWrite(Hum,1);

            Ser.consolWrite(Lig);
            Ser.fileWrite(Lig,2);

            Ser.consolWrite(Press);
            Ser.fileWrite(Press,3);

        }
};




 #endif //SCHEDULER_H