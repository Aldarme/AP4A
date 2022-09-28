/**
 * @author choulot_hugo
 * @file Sensor.hpp
 * @date 20/09/2022
 * @brief Classe mère des différents capteurs
 */

//
// Define guards
#ifndef Projet_AP4A_SENSOR_H
#define Projet_AP4A_SENSOR_H

#include <iostream>
#include <string>
#include "Scheduler.hpp"
#include "Server.hpp"

/**
 * @enum ESensors
 * @brief Liste les differents types de capteurs
 */
enum ESensors {
    e_temperature,
    e_humidity,
    e_light,
    e_pression
};

/**
 * @class Sensor
 * @brief Classe mère des différents capteurs
 */
class Sensor
{

protected :

    //attributs
    int m_valeur;
    ESensors m_name;

        /**
     * @brief permet de générer des valeurs aléatoires de int pour les différents capteurs
     * @return int
     * @param const ESensors name
     */

public :

    //Definition de la forme canonique

    //constructeur par défaut
    Sensor();

    //constructeur par valeur
    Sensor(const ESensors param_name);

    //constructeur par recopie
    Sensor(const Sensor& s);

    //destructeur
    ~Sensor();

    //operator
    Sensor& operator=(const Sensor& s);

    int aleaGenVal();

    ESensors getName();
    
    friend class Scheduler;

};

/**
 * @class Temperature
 * @brief Permet de générer des objets capteurs de température
 */
class Temperature : public Sensor {
};

/**
 * @class Humidity
 * @brief Permet de générer des objets capteurs d'humidité
 */
class Humidity : public Sensor {
};

/**
 * @class Light
 * @brief Permet de générer des objets capteurs de lumière
 */
class Light : public Sensor {
};

/**
 * @class Pression
 * @brief Permet de générer des objets capteurs de pression
 */
class Pression : public Sensor {
};

#endif // Projet_AP4A_SENSOR_H