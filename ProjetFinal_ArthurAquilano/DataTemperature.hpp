/**
 * @author Arthur
 * @file DataTemperature.hpp
 * @date 03/10/22
 * @brief Déclaration de la classe DataTemperature
 */

//DEFINE_GUARDS
#ifndef DATATEMPERATURE_H
#define DATATEMPERATURE_H

#include "Sensor.hpp"

/**
* @class DataTemperature
* @brief Déclaration de la classe DataTemperature
*/
class DataTemperature: public Sensor<float>
{
public:
    //Méthodes définies dans DataHumidity.hpp
    float getVal();
    float aleaGenVal(float minValue, float maxValue);
};

#endif //DATATEMPERATURE_H