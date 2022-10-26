/**
 * @author Planchin Arnaud
 * @file Humidity.hpp
 * @date 18/10/2022
 * @brief Définition de la classe Humidity, classe fille de Sensor 
 */

#ifndef HUMIDITY_H
#define HUMIDITY_H

#include "Sensor.hpp"

class Humidity: public Sensor<float>
{
public:

    /**
     * @brief Forme Canonique de Coplien de la classe Humidity
     */
    Humidity(){};
    Humidity(const Humidity& hum){};
    virtual ~Humidity(){};

    /**
     * @brief Récupère une valeur
     * @return Une data de type float
     */
    float GetData();

    /**
     * @brief Génère une valeur qui suit une variation entre deux valeurs: min, max 
     * @return Une data de type float
     * @param min - valeur minimum du capteur de type float
     * @param max - valeur maximum du capteur de type float
     */
    float aleaGenVal(float min, float max);
};

#endif // HUMIDITY_H