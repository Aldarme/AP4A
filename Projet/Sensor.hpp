/**
 * @file Sensor.hpp
 * @author Aurélien PETRA
 * @brief Classe mère de tous les capteurs, elle possède des méthodes génériques à tous les capteurs d'un avion de ligne
 * @version 0.1
 * @date 2022-10-09
 *
 * @copyright Copyright (c) 2022
 *
 */

// Define guards
#ifndef SENSOR_H
#define SENSOR_H

#include <cstdlib>
#include <ctime>

/**
 * @class sensor
 * @brief Classe mère de tous les capteurs, elle possède des méthodes génériques à tous les capteurs
 */
class sensor
{
public:
    int m_min;
    int m_max;
    sensor() : m_min(), m_max() {}
    sensor(const sensor &param_s) : m_min(param_s.m_min), m_max(param_s.m_max) {}
    ~sensor() {}
    sensor &operator=(const sensor &);

    /**
     * @brief Génère une valeur aléatoire comprise entre les attributs m_min et m_max;
     *
     * @return int
     */
    int aleaGenVal();
};

#endif // SENSOR_H