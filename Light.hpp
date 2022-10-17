#ifndef LIGHT_H
#define LIGHT_H

#include <iostream>
#include <cstdio>
#include "Sensor.hpp"


class Light : public Sensor<bool>
{
    protected : 
        bool aleaGenVal() {
            return rand()%2==0?(*this).min:(*this).max; // genere un nombre 0 ou 1, si c'est 0 alors false, sinon true
        };
        

    public : 
        Light(){
            (*this).min = false;
            (*this).max = true;
            (*this).value = aleaGenVal();
        };

};

#endif