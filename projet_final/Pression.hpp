/**
 * @author lois ROGER
 * @file Pression.hpp
 * @date 05/09/2022
 * @brief capteur de pression
*/

#ifndef PRESSION_H
#define PRESSION_H
#include "Sensor.hpp"

class Pression : public Sensor<int>
{
    public:
        int getVal();
        int aleaGenVal(int mini, int maxi);
       

};

#endif