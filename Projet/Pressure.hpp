/**
 * @author Erhart Eliott
 * @file Pressure.hpp
 * @date 03/10/2022
 * @brief Définition de la classe Pressure
 */

#include "Sensor.hpp"

/** 
 * @class Pressure
 * @brief Implémentation classe Pressure
 */
class Pressure: public Sensor <int>
{
public: 
        /// @brief Forme canonique de Coplien de la classe Pressure
        Pressure(){};
        Pressure(const Pressure& press){};
        virtual ~Pressure(){};

        /// @brief Génère une valeur aléatoire de type int
        /// @param min 
        /// @param max 
        /// @return une valeur aléatoire
        int aleaGenVal(int min, int max);
};