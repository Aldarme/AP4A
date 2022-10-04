/**
 * @author Cameron ROCHEBILLARD
 * @file Sensor.hpp
 * @date 27/09/2022
 * @brief permet de réunir et envoyer les données des capteurs
 */

 //
 //Define guards 
 #ifndef SENSOR_H
 #define SENSOR_H


/**
 * @class Sensor
 * récupère et renvoie les données des capteur
 */

class Sensor
{
    public : 
        int getData(int, int);
        int aleaGenVal(int, int);
};

class Temperature: public Sensor
{
    public:
        int T_min ;
        int T_max ;
};

class Humidity: public Sensor
{
    public:
        int H_min;
        int H_max;
};

class Light: public Sensor
{
    public:
        int L_min;
        int L_max;
};

class Pression: public Sensor
{
    public:
        int P_min;
        int P_max;
};

 #endif //SENSOR_H