/*
* @author Metral Greg
* @file Sensor.hpp
* @date 17/10/2022
* @brief classe mère des différents sensors
*/


#ifndef SENSOR_H
#define SENSOR_H

#include <iostream>
#include <cstdio>

using namespace std;


template <typename T> //classe template pour généré des filles avec un type différent
class Sensor 
{
    protected :
        T m_min; //min et max pour aleagenval
        T m_max;
        virtual T aleaGenVal() = 0; //classe abstraite, on modifie dans chaque classe fille
        T m_value;

    public :
        Sensor()
        {

        }; 
        virtual T getData()//retourne la valeur contnue dans le sensor en question
        { 
            (*this).m_value = aleaGenVal();
            return (*this).m_value;
        };
};

#endif