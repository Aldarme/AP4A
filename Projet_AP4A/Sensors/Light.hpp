//
// Created by jules on 01/10/22.
//

#ifndef PROJET_AP4A_LIGHT_HPP
#define PROJET_AP4A_LIGHT_HPP

#include "../sensor.hpp"

class Light : public Sensor<bool>
{
public:
    Light();
    bool aleaGenVal();
    bool getData();
};

#endif //PROJET_AP4A_LIGHT_HPP
