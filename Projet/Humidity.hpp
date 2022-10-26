/**
 * @author Erhart Eliott
 * @file Humidity.hpp
 * @date 03/10/2022
 * @brief Définition de la classe Humidity
 */

#include "Sensor.hpp"

/** 
 * @class Humidity
 * @brief Implémentation classe Humidity
 */
class Humidity: public Sensor <float>
{
public: 
        /// @brief Forme canonique de Coplien de la classe Humidity
        Humidity(){};
        Humidity(const Humidity& humi){};
        virtual ~Humidity(){};

        /// @brief Génère une valeur aléatoire de type float
        /// @param min 
        /// @param max 
        /// @return une valeur aléatoire
        float aleaGenVal(float min, float max);
};