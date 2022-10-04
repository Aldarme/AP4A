/**
 * @author Thibaud Leclere <thibaud.leclere@utbm.fr>
 * @file Sensor.hpp
 * @date 28/09/2022
 * @brief Définition de la class Sensor et de ses classes héritées (Sensor spécifiques)
 * @brief Les Sensors permettent de générer et récupérer une valeur correspondant à leur type
 */

// Define guards
#ifndef SENSOR_H
#define SENSOR_H

#include <ctime>
#include <cstdlib>
#include <cmath>

/**
 * @class Sensor
 * @brief Classe de base pour les Sensor
 */
class Sensor
{
public:
    //Forme canonique
    Sensor();
    ~Sensor();
    Sensor(const Sensor& s);
    Sensor& operator=(const Sensor& s);

    /**
     * @brief Retourne une donnée générée selon les bornes minimales et maximales
     * @return La valeur générée par le Sensor
     */
    int getData();

protected:
    int m_minValue = 0;
    int m_maxValue = 100;

    /**
     * @brief Génère une donnée aléatoire comprise entre les bornes minimales et maximales
     * @return La valeur aléatoire générée
     */
    int aleaGenVal();
};

/**
 * @class HumiditySensor
 * @brief Sensor spécifique à l'humidité
 * @brief Les données générées sont comprises entre 0% et 100% d'humidité
 */
class HumiditySensor : public Sensor
{
public:
    HumiditySensor();
};

/**
 * @class LightSensor
 * @brief Sensor spécifique à la lumière
 * @brief Les données générées sont 1 si la lumière est allumée, sinon 0
 */
class LightSensor : public Sensor
{
public:
    LightSensor();
};

/**
 * @class PressureSensor
 * @brief Sensor spécifique à la pression atmosphérique
 * @brief Les données générées sont comprises entre 100 hPa et 1014 hPa
 */
class PressureSensor : public Sensor
{
public:
    PressureSensor();
};

/**
 * @class TemperatureSensor
 * @brief Sensor spécifique à la température
 * @brief Les données générées sont comprises entre 280K et 305K
 */
class TemperatureSensor : public Sensor
{
public:
    TemperatureSensor();
};

#endif // SENSOR_H
