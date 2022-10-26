/**
 * @author Erhart Eliott
 * @file Light.hpp
 * @date 03/10/2022
 * @brief Définition de la classe Light
 */

#include "Sensor.hpp"

/** 
 * @class Light
 * @brief Implémentation classe Light
 */
class Light: public Sensor <bool>
{
public: 
        /// @brief Forme canonique de Coplien de la classe Light
        Light(){};
        Light(const Light& light){};
        virtual ~Light(){};

        /// @brief Génère une valeur aléatoire de type bool
        /// @param min 
        /// @param max 
        /// @return une valeur aléatoire
        bool aleaGenVal(bool min, bool max);
};