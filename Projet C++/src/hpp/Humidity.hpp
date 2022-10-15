/*
@author BENEDUCI Marie
@file  Humidity.hpp
@date 26/09/2022
@brief  Déclaration de la Classe capteur permetant d'avoir les données d'humidité
*/

#ifndef SENSOR_HPP
#define SENSOR_HPP
#include "Sensor.hpp"
#endif 

#ifndef HUMIDITY_HPP
#define HUMIDITY_HPP

class Humidity : public Sensor<float>
{
public:
    Humidity(); //Constructeur par défaut
    float aleaGenVal(){
    // float random
        std::random_device rd;
        std::default_random_engine eng(rd());
        std::uniform_real_distribution<float> distr(0, 40);
        std::setprecision(6);
        float randomData = distr(eng);
        return randomData;
    };

};

#endif 