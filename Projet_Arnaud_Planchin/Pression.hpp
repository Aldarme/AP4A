/**
 * @author Planchin Arnaud
 * @file Pression.hpp
 * @date 18/10/2022
 * @brief Définition de la classe Pression, classe fille de Sensor 
 */

#ifndef PRESSION_H
#define PRESSION_H

#include "Sensor.hpp"

class Pression: public Sensor<int>
{
public:

    /**
     * @brief Forme Canonique de Coplien de la classe Pression
     */
    Pression(){};
    Pression(const Pression& pres){};
    virtual ~Pression(){};

    /**
     * @brief Récupère une valeur
     * @return Une data de type int
     */
    int GetData();

    /**
     * @brief Génère une valeur qui suit une variation entre deux valeurs: min, max 
     * @return Une data de type int
     * @param min - valeur minimum du capteur de type int 
     * @param max - valeur maximum du capteur de type int
     */
    int aleaGenVal(int min, int max);
};

#endif // PRESSION_H