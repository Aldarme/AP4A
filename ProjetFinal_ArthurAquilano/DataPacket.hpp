/**
 * @author Arthur
 * @file DataPacket.hpp
 * @date 03/10/22
 * @brief Déclaration de la classe DataPacket
 */

//DEFINE_GUARDS
#ifndef DATAPACKET_H
#define DATAPACKET_H

#include "DataLight.hpp"
#include "DataHumidity.hpp"
#include "DataTemperature.hpp"
#include "DataPressure.hpp"

/**
* @class DataPacket
* @brief Déclaration de la classe DataPacket
*/
class DataPacket
{
public:
    float temperature;
    float humidity;
    bool light;
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