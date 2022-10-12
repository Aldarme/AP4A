/**
 * @file Sensor.hpp
 * @author Loric Ravassard
 * @brief Génère aléatoirement des valeurs en fonction des min et max de ces derniers
 * @version 1
 * @date 2022-09-28
 */

#ifndef SENSOR_H
#define SENSOR_H

#include <string>

/**
 * @class Sensor
 * @brief Génère aléatoirement des valeurs en fonction des min et max de ces derniers
 */
class Sensor
{
  protected:
    int m_min, m_max; ///minimum et  maximum des valeurs à générer aléatoirement
    std::string m_unit; ///unité de mesure du capteur
    
  public:
    Sensor(){};
    Sensor(const Sensor& other_p) : m_max(other_p.m_max), m_min(other_p.m_min), m_unit(other_p.m_unit){};
    virtual ~Sensor(){};
    Sensor& operator=(const Sensor& other_p);

    /**
     * @brief retourne une valeur générée aléatoirement
     * 
     * @return int 
     */
    int getData();

    /**
     * @brief retourne une valeur aléatoire entre min et max
     *  qui sont définis dans les différents types de capteur
     * 
     * @param min_p 
     * @param max_p 
     * @return int 
     */
    int aleaGenVal(int min_p, int max_p); //Type T

    /**
     * @brief récupère l'unité du capteur
     * 
     * @return std::string 
     */
    std::string getUnit() const;
};

#endif