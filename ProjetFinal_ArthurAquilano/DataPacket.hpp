/**
 * @author Arthur
 * @file DataPacket.hpp
 * @date 03/10/22
 * @brief Déclaration de la classe DataPacket
 */

//DEFINE_GUARDS
#ifndef DATAPACKET_H
#define DATAPACKET_H

#include "Data.hpp"

/**
* @class DataPacket
* @brief Déclaration de la classe DataPacket
*/
class DataPacket
{
public:
    int temperature;
    int humidity;
    int light;
    int pressure;

    /** 
    * @brief Déclaration de la forme canonique de coplien
    * @return Rien
    * @param Ceux par défaut
    */
    DataPacket(): temperature(), humidity(), light(), pressure(){};
    DataPacket(const DataPacket& d): temperature(d.temperature), humidity(d.humidity), light(d.light), pressure(d.pressure){};
    ~DataPacket(){};
};

#endif //DATAPACKET.H