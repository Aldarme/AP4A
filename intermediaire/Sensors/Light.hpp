/**
 * @author Céliane ALLAIRE
 * @file Light.hpp
 * @date 28/09/2022
 * @brief 
 * */

//
//Define guards
#ifndef LIGHT_H
#define LIGHT_H
#include "../Sensor.hpp"


/**
 * @class Light
 * @brief 
 */
class Light : public Sensor
{
public:
// Definition de la forme canonique
    Light(); //Constructeur pas défaut
    Light(const Light& param_s); //Constructeur par recopie
    Light& operator=(const Light& param_s); //Opérateur d'affectation
    ~Light(); //Destructeur

    float aleaGenVal(); //Nous pouvons déclarer le type dans la classe sensor pour le rendu intermédiaire
    float getData();
};


#endif  // LIGHT_H