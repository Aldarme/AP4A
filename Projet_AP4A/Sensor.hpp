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

    int& aleaGenVal();

    ESensors getName();

};

/**
 * @class Temperature
 * @brief Permet de générer des objets capteurs de température
 */
class Temperature : public Sensor {

    private :

    public:

    //constructeur par défaut
    Temperature();

    //constructeur par recopie
    Temperature(const Temperature& t);

    /**
     * @brief permet de récupérer les données des capteurs
     * @return int
     * @param
     */
    int getDataT();

    void setDataT(const int& i);

};

/**
 * @class Humidity
 * @brief Permet de générer des objets capteurs d'humidité
 */
class Humidity : public Sensor {

    private :

    public:

    //constructeur par défaut
    Humidity();

    //constructeur par recopie
    Humidity(const Humidity& h);

    /**
     * @brief permet de récupérer les données des capteurs
     * @return int
     * @param
     */
    int getDataH();

    void setDataH(const int& i);
};

/**
 * @class Light
 * @brief Permet de générer des objets capteurs de lumière
 */
class Light : public Sensor {

    private :

    public :

    //constructeur par défaut
    Light();

    //constructeur par recopie
    Light(const Light& l);

    /**
     * @brief permet de récupérer les données des capteurs
     * @return int
     * @param
     */
    int getDataL();

    void setDataL(const int& i);
};

/**
 * @class Pression
 * @brief Permet de générer des objets capteurs de pression
 */
class Pression : public Sensor {

    private :

    public :

    //constructeur par défaut
    Pression();

    //constructeur par recopie
    Pression(const Pression& p);

    /**
     * @brief permet de récupérer les données des capteurs
     * @return int
     * @param
     */
    int getDataP();

    void setDataP(const int& i);
};

#endif // Projet_AP4A_SENSOR_H