/**
 * @file Sensor.hpp
 * @author Loric Ravassard
 * @brief Génère aléatoirement des valeurs en fonction des min et max des capteurs
 * @version 2
 * @date 2022-09-28
 */

#ifndef SENSOR_H
#define SENSOR_H

#include <string>

/**
 * @class Sensor
 * Class abstraite
 * @brief Génère aléatoirement des valeurs en fonction des min et max des capteurs
 */
template <typename T> 
class Sensor
{
  protected:
    T m_min, m_max; ///minimum et  maximum des valeurs à générer aléatoirement
    std::string m_unit; ///unité de mesure du capteur
    int m_interval; ///l'intervalle de temps entre 2 récupérations de données du capteur
    std::string m_name; ///le nom du capteur
    
  public:
    Sensor<T>() : m_max(), m_min(), m_unit(), m_interval(), m_name(){};
    Sensor<T>(const Sensor<T>& other_p) : m_max(other_p.m_max), m_min(other_p.m_min), m_unit(other_p.m_unit), m_interval(other_p.m_interval), m_name(other_p.m_name){};
    virtual ~Sensor<T>(){};
    Sensor<T>& operator=(const Sensor<T>& other_p)
    {
      m_max = other_p.m_max;
      m_min = other_p.m_min;
      m_unit = other_p.m_unit;
      return *this;
    };

    /**
     * @brief retourne une valeur générée aléatoirement
     * 
     * @return T 
     */
    T getData()
    {
      return this->aleaGenVal();
    };

    /**
     * Méthode virtuelle pure
     * @brief retourne une valeur aléatoire entre min et max
     *  qui sont définis dans les différents types de capteur
     * 
     * @return T
     */
    virtual T aleaGenVal() = 0;

    /**
     * @brief récupère l'unité du capteur
     * 
     * @return std::string 
     */
    std::string getUnit() const
    {
      return this->m_unit;
    };

    /**
     * @brief récupère le nom du capteur
     * 
     * @return std::string 
     */
    std::string getName() const
    {
      return m_name;
    };

    /**
     * @brief récupère l'intervalle de temps de récupération des données du capteur
     * 
     * @return int 
     */
    int getInterval() const
    {
      return m_interval;
    };
};

#endif