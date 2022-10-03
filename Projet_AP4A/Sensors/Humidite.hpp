//
// Created by jules on 01/10/22.
//

#ifndef PROJET_AP4A_HUMIDITE_HPP
#define PROJET_AP4A_HUMIDITE_HPP

#include "../sensor.hpp"

class Humidite : public Sensor<float>
{
public:
    Humidite();
    Humidite(const Humidite& param_h);
    ~Humidite();
    Humidite& operator=(const Humidite& param_h);
};

#endif //PROJET_AP4A_HUMIDITE_HPP
