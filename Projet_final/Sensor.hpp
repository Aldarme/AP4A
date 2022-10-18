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

template <class S> 
class Sensor
{
    public : 
        S getData(S, S);
        S aleaGenVal(S, S);
};

 #endif //SENSOR_H