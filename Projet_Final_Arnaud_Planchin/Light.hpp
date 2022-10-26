/**
 * @author Planchin Arnaud
 * @file Light.hpp
 * @date 18/10/2022
 * @brief Définition de la classe Light, classe fille de Sensor 
 */

#ifndef LIGHT_H
#define LIGHT_H

#include "Sensor.hpp"

class Light: public Sensor<bool>{
public:

    /**
     * @brief Forme Canonique de Coplien de la classe Light
     */
    Light(){};
    Light(const Light& lum){};
    virtual ~Light(){};

    /**
     * @brief Récupère une valeur
     * @return Une data de type bool
     */
    bool GetData();

    /**
     * @brief Génère une valeur aléatoire entre 1 et 0
     * @return Une data de type bool
     * @param min - valeur minimum du capteur de type bool
     * @param max - valeur maximum du capteur de type bool
     */
    bool aleaGenVal(bool min, bool max);
};

#endif // LIGHT_H