#ifndef PRESSION_H
#define PRESSION_H
#pragma once

#include "Sensor.h"
#include <iostream>

using namespace std;

class Pression : public Sensor<int>
{
    private:
    public:
        void sense();
        Pression()
        {
             this->value = Sensor<int>::aleaGenVal();
        }
        ~Pression()
         {

          }
};

#endif