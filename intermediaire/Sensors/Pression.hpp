/**
 * @author Céliane ALLAIRE
 * @file Pression.hpp
 * @date 28/09/2022
 * @brief 
 * */

//
//Define guards
#ifndef PRESSION_H
#define PRESSION_H
#include "../Sensor.hpp"


/**
 * @class Pression
 * @brief 
 */
class Pression : public Sensor
{
public:
// Definition de la forme canonique
    Pression(); //Constructeur pas défaut
    Pression(const Pression& param_s); //Constructeur par recopie
    Pression& operator=(const Pression& param_s); //Opérateur d'affectation
    ~Pression(); //Destructeur

    float aleaGenVal(); //Nous pouvons déclarer le type dans la classe sensor pour le rendu intermédiaire
    float getData();
};


#endif  // PRESSION_H