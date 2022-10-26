/**
 * @author Planchin Arnaud
 * @file Temperature.hpp
 * @date 18/10/2022
 * @brief Définition de la classe Temperature, classe fille de Sensor 
 */

#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include "Sensor.hpp"

class Temperature: public Sensor<float>
{
public:
    
    /**
     * @brief Forme Canonique de Coplien de la classe Temperature
     */
    Temperature(){}
    Temperature(const Temperature& temp){}
    virtual ~Temperature(){}

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

#endif // TEMPERATURE_H