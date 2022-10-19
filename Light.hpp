/*
* @author Metral Greg
* @file Light.hpp
* @date 17/10/2022
* @brief capteur de lumière, génère et stock des randoms bool
*/


#ifndef LIGHT_H
#define LIGHT_H

#include <iostream>
#include <cstdio>
#include "Sensor.hpp"


class Light : public Sensor<bool>
{
    protected : 
        bool aleaGenVal() {
            return rand()%2==0?(*this).m_min:(*this).m_max; // genere un nombre 0 ou 1, si c'est 0 alors false, sinon true
        };
        

    public : 
        Light(){
            (*this).m_min = false;
            (*this).m_max = true;
            (*this).m_value = aleaGenVal();
        };

};

#endif