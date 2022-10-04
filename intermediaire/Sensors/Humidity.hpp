/**
 * @author Céliane ALLAIRE
 * @file Humidity.hpp
 * @date 28/09/2022
 * @brief 
 * */

//
//Define guards
#ifndef HUMIDITY_H
#define HUMIDITY_H
#include "../Sensor.hpp"


/**
 * @class Humidity
 * @brief 
 */
class Humidity : public Sensor
{
public:
// Definition de la forme canonique
    Humidity(); //Constructeur pas défaut
    Humidity(const Humidity& param_s); //Constructeur par recopie
    Sensor& operator=(const Sensor& param_s); //Opérateur d'affectation
    ~Humidity(); //Destructeur

    float aleaGenVal(); //Nous pouvons déclarer le type dans la classe sensor pour le rendu intermédiaire
    float getData();
};


#endif  // HUMIDITY_H