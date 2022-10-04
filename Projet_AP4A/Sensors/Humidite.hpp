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
    Humidite(const Humidite& h_p);
    ~Humidite();
    Humidite& operator=(const Humidite& h_p);
};

#endif //PROJET_AP4A_HUMIDITE_HPP
