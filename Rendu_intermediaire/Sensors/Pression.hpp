//
// Created by jules on 01/10/22.
//

#ifndef PROJET_AP4A_PRESSION_HPP
#define PROJET_AP4A_PRESSION_HPP

#include "../sensor.hpp"

class Pression : public Sensor<TYPE>
{
public:
    Pression();
    Pression(const Pression& p_p);
    ~Pression();
    Pression& operator=(const Pression& p_p);
};

#endif //PROJET_AP4A_PRESSION_HPP
