/**
 * @author choulot_hugo
 * @file Sensor.hpp
 * @date 20/09/2022
 * @brief Classe mère des différents capteurs
 */

//
// Define guards
#ifndef Projet_AP4A_HUMIDITY_H
#define Projet_AP4A_HUMIDITY_H

#include <iostream>
#include <string>

#include "Sensor.hpp"

/**
 * @class Humidity
 * @brief Permet de générer des objets capteurs d'humidité
 */
class Humidity : public Sensor<float> {

    public:

    //constructeur par défaut des capteurs Humidity
    Humidity();

    //constructeur par recopie des capteurs Humidity
    Humidity(const Humidity& h);

        //destructeur
    ~Humidity();

    float aleaGenVal();

};

#endif // Projet_AP4A_HUMIDITY_H