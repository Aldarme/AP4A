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
    T aleaGenVal();

    /**
    * @brief permet de récupérer la valeur des capteurs
    * @return int
    * @param void
    */
    T getData();

};

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

};

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

};

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

};

/**
 * @class Pression
 * @brief Permet de générer des objets capteurs de pression
 */
class Pression : public Sensor<int> {

    public :

    //constructeur par défaut des capteurs Pression
    Pression();

    //constructeur par recopie des capteurs Pression
    Pression(const Pression& p);

    //destructeur
    ~Pression();

};

#endif // Projet_AP4A_SENSOR_H
