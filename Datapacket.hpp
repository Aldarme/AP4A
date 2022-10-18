#ifndef DATAPACKET_H
#define DATAPACKET_H

#include "Datapacket.hpp"

class Datapacket
{
public:
    float temperature;
    float humidity;
    bool light;
    int pressure;


    Datapacket(): temperature(), humidity(), light(), pressure(){};
    Datapacket(const Datapacket& d): temperature(d.temperature), humidity(d.humidity), light(d.light), pressure(d.pressure){};
    ~Datapacket(){};
};

#endif