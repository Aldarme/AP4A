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
template <class T1, class T2>
class sensor
{
protected:
    T1 m_data;

public:
    sensor() : m_data() {}
    sensor(const sensor &s) : m_data(s.m_data) {}
    ~sensor() {}
    sensor &operator=(const sensor &s)
    {
        m_data = s.m_data;
        return *this;
    }

    /**
     * @brief Génère une valeur aléatoire à partir de l'attribut m_data
     *
     * @return T2
     */
    virtual T2 &aleaGenVal() = 0;

    /**
     * @brief Initialise m_data avec une valeur aléatoire
     * 
     * @return T2& 
     */
    virtual T2 &aleaInitVal() = 0;

    /**
     * @brief Get the Data object
     * 
     * @return T1 
     */
    T1 getData()
    {
        return m_data;
    }
};

#endif // SENSOR_H