#ifndef DATAPACKET_H
#define DATAPACKET_H

#include "Temperature.hpp"
#include "Pression.hpp"
#include "Light.hpp"
#include "Humidity.hpp"

class Datapacket
{
public:
    float temperature;
    float humidity;
    bool light;
    int pression;


    Datapacket(): temperature(), humidity(), light(), pression(){};
    ~Datapacket(){};
};

#endif
