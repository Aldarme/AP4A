/**
 * @author Thibaud Leclere <thibaud.leclere@utbm.fr>
 * @file Sensor.hpp
 * @date 28/09/2022
 * @brief Définition de la class Sensor
 * @brief Les Sensors permettent de générer et récupérer une valeur correspondant à leur type
 * @brief La classe étant un template, l'implémentation est faite directement dans le header
 */

// Define guards
#ifndef SENSOR_H
#define SENSOR_H

#include <ctime>
#include <cstdlib>
#include <cmath>
#include <string>

#include "StructSensorData.hpp"

/**
 * @class Sensor
 * @brief Classe de base pour les Sensor
 */
template<typename T>
class Sensor
{
protected:
    T m_minValue;       //Valeur minimale pouvant être renvoyée par le sensor
    T m_maxValue;       //Valeur maximale pouvant être renvoyée par le sensor
    int m_freq;         //Fréquence de rafraichissement du sensor
    std::string m_name; //Nom à afficher du sensor
    std::string m_unit; //Unité des valeurs envoyées par le sensor

    /**
     * @brief Génère une donnée aléatoire comprise entre les bornes minimales et maximales
     * @return La valeur aléatoire générée
     */
    T aleaGenVal()
    {
        if(std::is_same<T, bool>::value)
        {
            //Dans le cas d'un booléen, un static_cast<bool> ne fait pas de sens
            //On fait donc un traitement exceptionnel, pour retourner 0 ou 1, qui peuvent être interprétés comme des booléens
            return rand()%2;
        }
        else
        {
            return m_minValue + static_cast<T>(rand()) / static_cast<T>(RAND_MAX / (m_maxValue - m_minValue));
        }
    }

public:
    //Forme canonique
    Sensor<T>() : m_minValue(0), m_maxValue(1), m_freq(0), m_name("default"), m_unit("") {}
    virtual ~Sensor<T>() = default;
    Sensor<T>(const Sensor<T>& s) : m_minValue(s.m_minValue), m_maxValue(s.m_maxValue), m_freq(s.m_freq), m_name(s.m_name), m_unit(s.m_unit) {}
    Sensor<T>& operator=(const Sensor<T>& s)
    {
        m_minValue = s.m_minValue;
        m_maxValue = s.m_maxValue;
        m_freq = s.m_freq;
        m_name = s.m_name;
        m_unit = s.m_unit;
        return *this;
    }

    /**
     * @brief Retourne une structure SensorData contenant les informations du Capteur
     * @return Structure SensorData, contenant le nom, l'unité et la valeur du capteur
     */
    SensorData getData()
    {
        SensorData data;
        data.sensorName = m_name;
        data.sensorUnit = m_unit;
        data.sensorValue = std::to_string(aleaGenVal());

        return data;
    }

    /**
     * @brief Accesseur de la fréquence du sensor
     * @return La fréquence du sensor
    */
    int getFreq()
    {
        return m_freq;
    }

    /**
     * @brief Mutateur de la fréquence du sensor
     * @param freq Nouvelle fréquence du sensor
    */
    void setFreq(int freq)
    {
        m_freq = freq;
    }
};

#endif // SENSOR_H
