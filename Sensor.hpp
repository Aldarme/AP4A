/**
* @author laduguie
* @file Sensor.hpp
* @date 28/09/2022
* @brief définition de la classe Sensor
*/

#ifndef SENSOR_H
#define SENSOR_H
#include <iostream>

template <class T>  //on utilise un template sur la classe Sensor
class Sensor
{
    protected:
        virtual T aleaGenVal() =0; //on rajoute virtual pour utiliser le type dynamique

        /*l'utilisation de template permet de donner plusieurs types à notre fonction aleaGenVal
            m_min et m_max sont de type T et pourront prendre les types int, float et bool grâce au template*/
            
        T m_min;
        T m_max;
    public:
        virtual T getData() 
        {
            return aleaGenVal();
        };

        Sensor(){} //constructeur par défaut
        Sensor(const Sensor&); //constructeur par recopie
        Sensor &operator=(const Sensor&); //operateur d'afffectation
        virtual ~Sensor(){} //Destructeur

};

#endif
