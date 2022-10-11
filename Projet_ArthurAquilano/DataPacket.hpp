/**
 * @author Arthur
 * @file DataPacket.hpp
 * @date 03/10/22
 * @brief Déclaration de la classe DataPacket
 */

//DEFINE_GUARDS
#pragma once
#ifndef DATAPACKET_H
#define DATAPACKET_H

#include "Data.hpp"

class DataPacket
{
public:
    DataPacket(): temperature(), humidity(), light(), pressure(){};
    DataPacket(const DataPacket& d): temperature(d.temperature), humidity(d.humidity), light(d.light), pressure(d.pressure){};
    ~DataPacket(){};

    int temperature;
    int humidity;
    int light;
    int pressure;
};

#endif //DATAPACKET.H