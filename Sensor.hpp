#ifndef SENSOR_H
#define SENSOR_H

#include <iostream>
#include <cstdio>

using namespace std;


template <typename T> //classe template pour généré des filles avec un type différent
class Sensor 
{
    protected :
        T min; //min et max pour aleagenval
        T max;
        virtual T aleaGenVal() = 0; //classe abstraite, on modifie dans chaque classe fille
        T value;

    public :
        Sensor()
        {

        }; 
        virtual T getData()//retourne la valeur contnue dans le sensor en question
        { 
            (*this).value = aleaGenVal();
            return (*this).value;
        };
};

#endif