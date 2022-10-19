/**
 *@author Lola ROQUILLON 
 *@file Pression.hpp
 *@date 28/09/2022
 *@brief cette classe represente un capteur de pression
 */
#include "Sensor.hpp"
#ifndef PRESSION_H
#define PRESSION_H 

class Pression : public Sensor <int>
{
    public:
    //forme canonique
        Pression()=default;
        virtual ~Pression()=default;
        int DataPression();

    private:
    //valeurs minimun et maximun que peut générer le nombre aléatoire de pression
        int m_min=800;
        int m_max=1200;
};
#endif //PRESSION_H