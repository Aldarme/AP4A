/**
 * @author Arthur
 * @file DataHumidity.hpp
 * @date 03/10/22
 * @brief Déclaration de la classe DataHumidity
 */

//DEFINE_GUARDS
#ifndef DATAHUMIDITY_H
#define DATAHUMIDITY_H

#include "Sensor.hpp"

/**
* @class DataHumidity
* @brief Declaration de la classe DataHumidity
*/
class DataHumidity: public Sensor<float>
{
public:
    /** 
    * @brief Methode pour récupérer les valeurs générer aléatoirement
    * @return float
    * @param Aucun
    */
    float getVal();

    /** 
    * @brief Methode pour générer aléatoirement des valeurs
    * @return float
    * @param Deux float qui définissent l'étendu des valeurs prenables pour le capteur
    */
    float aleaGenVal(float minValue, float maxValue);
};

#endif //DATAHUMIDITY_H