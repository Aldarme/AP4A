/**
 * @author Arthur
 * @file DataLight.hpp
 * @date 03/10/22
 * @brief Déclaration de la classe DataLight
 */

//DEFINE_GUARDS
#ifndef DATALIGHT_H
#define DATALIGHT_H

#include "Sensor.hpp"

/**
* @class DataLight
* @brief Declaration de la classe DataLight
*/
class DataLight: public Sensor<bool>
{
public:
    //Méthodes définies dans DataHumidity.hpp
    bool getVal();
    bool aleaGenVal(bool minValue,bool maxValue);
};

#endif //DATALIGHT_H