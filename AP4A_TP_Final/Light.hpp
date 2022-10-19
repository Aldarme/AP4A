/**
 *@author Lola ROQUILLON 
 *@file Light.hpp
 *@date 28/09/2022
 *@brief classe qui represente un capteur de Lumière
 */
#include "Sensor.hpp"
#ifndef LIGHT_H
#define LIGHT_H

class Light : public Sensor <bool>
{
    public : 
        //forme canonique
        Light()=default;
        virtual ~Light()=default;
        bool DataLight();

    private :
        bool m_min=false;
        bool m_max=true;
};

#endif //LIGHT_H