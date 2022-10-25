/**
 * @author Arthur
 * @file DataPressure.hpp
 * @date 03/10/22
 * @brief Déclaration de la classe DataPressure
 */

//DEFINE_GUARDS
#ifndef DATAPRESSURE_H
#define DATAPRESSURE_H

#include "Sensor.hpp"

/**
* @class DataPressure
* @brief Declaration de la classe DataPressure
*/
class DataPressure: public Sensor<int>
{
public:
    //Méthodes définies dans DataHumidity.hpp
    int getVal();
    int aleaGenVal(int minValue, int maxValue);   
};

#endif //DATAPRESSURE_H