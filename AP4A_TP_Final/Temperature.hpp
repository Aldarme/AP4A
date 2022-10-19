/**
 *@author Lola ROQUILLON 
 *@file Temperature.hpp
 *@date 28/09/2022
 *@brief cette classe represente un capteur de température
 */
#include "Sensor.hpp"
#ifndef TEMPERATURE_H
#define TEMPERATURE_H

class Temperature : public Sensor <float>
{
    public : 
    //forme canonique
        Temperature()=default;
        virtual ~Temperature()=default;
        float DataTemperature();

    private :
    //valeurs minimun et maximun que peut générer le nombre aléatoire de température
        float m_min= 15;
        float m_max= 32;

};
#endif //TEMPERATURE_H