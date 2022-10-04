/**
 * @author Cameron ROCHEBILLARD
 * @file Sensor.cpp
 * @date 4/10/2022
 * @brief permet de réunir et envoyer les données des capteurs
 */

 //
 //Define guards 
 #ifndef SENSOR_H
 #define SENSOR_H

#include <Sensor.hpp>
#include <random>
#include <cstdlib> 


/**
 * @class Sensor
 * récupère et renvoie les données des capteur
 */

class Sensor
{
    public:
        int getData(int max, int min)
        {
            return aleaGenVal(max, min);
        }
        int aleaGenVal(int max, int min)
        {
            srand((unsigned)time(0)); 
            int i;
            int m = max - min;
            i = (rand()%m)+min;
            return i; 
        }
};

class Temperature : public Sensor
{
    public:
        int T_min = 23;
        int T_max = 25;

};

class Humidity : public Sensor
{
    public:
        int H_min = 40;
        int H_max = 60;

};

class Light : public Sensor
{
    public:
        int L_min = 0;
        int L_max = 1;

};

class Pression : public Sensor
{
    public:
        int P_min = 55;
        int P_max = 850;

};

 #endif //SENSOR_H