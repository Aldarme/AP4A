/**
 * @author Erhart Eliott
 * @file Temperature.hpp
 * @date 03/10/2022
 * @brief Définition de la classe Temperature
 */

#include "Sensor.hpp"

/** 
 * @class Temperature
 * @brief Implémentation classe Temperature
 */
class Temperature: public Sensor <float>
{
public: 
        /// @brief Forme canonique de Coplien de la classe Temperature
        Temperature(){};
        Temperature(const Temperature& temp){};
        virtual ~Temperature(){};

        /// @brief Génère ue valeur aléatoire de type float
        /// @param min 
        /// @param max 
        /// @return une valeur aléatoire
        float aleaGenVal(float min, float max);
};