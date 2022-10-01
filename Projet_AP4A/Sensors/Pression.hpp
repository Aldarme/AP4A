//
// Created by jules on 01/10/22.
//

#ifndef PROJET_AP4A_PRESSION_HPP
#define PROJET_AP4A_PRESSION_HPP

#include "../sensor.hpp"

class Pression : public Sensor<int>
{
public:
    Pression();
    int aleaGenVal(int param_minVal, int param_maxVal);
    int getData();
};

#endif //PROJET_AP4A_PRESSION_HPP
