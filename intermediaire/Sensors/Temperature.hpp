/**
 * @author Céliane ALLAIRE
 * @file Temperature.hpp
 * @date 28/09/2022
 * @brief 
 * */

//
//Define guards
#ifndef TEMPERATURE_H
#define TEMPERATURE_H
#include "../Sensor.hpp"


/**
 * @class Temperature
 * @brief 
 */
class Temperature : public Sensor
{
public:
// Definition de la forme canonique
    Temperature(); //Constructeur pas défaut
    Temperature(const Temperature& param_s); //Constructeur par recopie
    Temperature& operator=(const Temperature& param_s); //Opérateur d'affectation
    ~Temperature(); //Destructeur

    float aleaGenVal(); //Nous pouvons déclarer le type dans la classe sensor pour le rendu intermédiaire
    float getData();
};


#endif  // TEMPERATURE_H
