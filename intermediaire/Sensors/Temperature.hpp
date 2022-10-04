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
class Termperature : public Sensor
{
public:
// Definition de la forme canonique
    Termperature(); //Constructeur pas défaut
    Termperature(const Termperature& param_s); //Constructeur par recopie
    Termperature& operator=(const Termperature& param_s); //Opérateur d'affectation
    ~Termperature(); //Destructeur

    float aleaGenVal(); //Nous pouvons déclarer le type dans la classe sensor pour le rendu intermédiaire
    float getData();
};


#endif  // TEMPERATURE_H
