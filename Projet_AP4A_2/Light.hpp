/**
 * @author choulot_hugo
 * @file Sensor.hpp
 * @date 20/09/2022
 * @brief Classe mère des différents capteurs
 */

//
// Define guards
#ifndef Projet_AP4A_LIGHT_H
#define Projet_AP4A_LIGHT_H

#include <iostream>
#include <string>

#include "Sensor.hpp"

/**
 * @class Light
 * @brief Permet de générer des objets capteurs de lumière
 */
class Light : public Sensor<bool> {

    public :

    //constructeur par défaut des capteurs Light
    Light();

    //constructeur par recopie des capteurs Light
    Light(const Light& l);

    //destructeur
    ~Light();

    bool aleaGenVal();

};

#endif // Projet_AP4A_LIGHT_H