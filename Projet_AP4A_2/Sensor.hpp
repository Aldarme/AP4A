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

/**
 * @enum ESensors
 * @brief Liste les differents types de capteurs
 */
enum ESensors
{

    e_temperature,
    e_humidity,
    e_light,
    e_pression

};

template <typename T>

/**
 * @class Sensor
 * @brief Classe mère des différents capteurs
 */
class Sensor
{

protected :

    //attributs
    T m_valeur;
    ESensors m_name;

public :

    //Définition de la forme canonique

    //constructeur par défaut
    Sensor<T>();

    //constructeur par valeur
    Sensor<T>(const ESensors param_name);

    //constructeur par recopie
    Sensor<T>(const Sensor<T>& s);

    //destructeur
    ~Sensor<T>();

    //operator
    Sensor<T>& operator=(const Sensor<T>& s);

    /**
     * @brief permet de générer des valeurs aléatoires de int pour les différents capteurs
     * @return int
     * @param void
     */
    virtual T aleaGenVal()=0;

    /**
    * @brief permet de récupérer la valeur des capteurs
    * @return int
    * @param void
    */
    T getData();

    friend class Scheduler;
    friend class Server;

};

#endif // Projet_AP4A_SENSOR_H
