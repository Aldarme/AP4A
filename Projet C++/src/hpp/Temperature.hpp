/*
@author BENEDUCI Marie
@file  Temperature.hpp
@date 26/09/2022
@brief  Déclaration de la Classe capteur permetant d'avoir les données de temperature
*/

#ifndef SENSOR_HPP
#define SENSOR_HPP
#include "Sensor.hpp"
#endif 


#ifndef TEMPERATURE_HPP
#define TEMPERATURE_HPP

class Temperature : public Sensor<float>
{
public:
    Temperature(); //Constructeur par défaut
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



