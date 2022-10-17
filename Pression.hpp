#ifndef PRESSION_H
#define PRESSION_H

#include <iostream>
#include <cstdio>
#include "Sensor.hpp"

class Pression : public Sensor<int>
{
    protected :
        int aleaGenVal()  {
            return (rand()%(max-min+1))+min; //genere random int entre min et max
        };


    public : 
        Pression(){
            min = 700;
            max = 1400;
            (*this).value = aleaGenVal();
        };

};

#endif