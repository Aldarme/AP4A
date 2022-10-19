/**
 *@author Lola ROQUILLON 
 *@file Humidity.hpp
 *@date 28/09/2022
 *@brief Classe qui représente un capteur d'humidité
 */

#include "Sensor.hpp"
#ifndef HUMIDITY_H
#define HUMIDITY_H

class Humidity : public Sensor <float>
{
    public : 
    //forme canonique
        Humidity()=default;
        virtual ~Humidity()=default;
        float DataHumidity();
    
    private :
    //valeurs minimun et maximun que peut générer le nombre aléatoire d'Humidité
        float m_min = 39.5;
        float m_max = 61.5;


};
#endif //HUMIDITY_H