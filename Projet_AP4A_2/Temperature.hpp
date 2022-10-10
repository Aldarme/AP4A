/**
 * @author choulot_hugo
 * @file Sensor.hpp
 * @date 20/09/2022
 * @brief Classe mère des différents capteurs
 */

//
// Define guards
#ifndef Projet_AP4A_TEMPERATURE_H
#define Projet_AP4A_TEMPERATURE_H

#include <iostream>
#include <string>

#include "Sensor.hpp"

/**
 * @class Temperature
 * @brief Permet de générer des objets capteurs de température
 */
class Temperature : public Sensor<float> {

    public:

    //constructeur par défaut des capteurs Température
    Temperature();

    //constructeur par recopie des capteurs Température
    Temperature(const Temperature& t);

    //destructeur
    ~Temperature();

    float aleaGenVal();

};

#endif // Projet_AP4A_TEMPERATURE_H
