/**
 * @file Package.hpp
 * @author Loric Ravassard
 * @brief regroupe toutes les données dans un packet pour pouvoir les exploiter
 * @version 2
 * @date 2022-10-05
 */

#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>
#include <vector>
#include <iostream>

/**
 * @class Package
 * @brief regroupe toutes les données dans un packet pour pouvoir les exploiter
 * 
 */
template <typename T>
class Package
{
  private:
    std::string m_date; ///la date de récupération de la donnée
    std::string m_name; ///le nom du capteur
    T m_value;          ///la valeur envoyée par le capteur
    std::string m_unit; ///l'unité de la mesure
  public:
    Package<T>() : m_date(), m_name(), m_value(), m_unit(){};
    Package<T>(const Package<T>& other_p) : m_date(other_p.m_date), m_name(other_p.m_name), m_value(other_p.m_value), m_unit(other_p.m_unit){};
    virtual ~Package<T>(){};
    Package<T>& operator=(const Package<T>& other_p)
    {
      m_date = other_p.m_date;
      m_name = other_p.m_name;
      m_value = other_p.m_value;
      m_unit = other_p.m_unit;
      return *this;
    };

    /**
     * @brief affecte les attributs du package aux données d'un capteur
     * 
     * @param date_p 
     * @param name_p 
     * @param value_p 
     * @param unit_p 
     */
    void addMeasure(std::string date_p, std::string name_p, T value_p, std::string unit_p)
    {
      m_date = date_p;
      m_name = name_p;
      m_value = value_p;
      m_unit = unit_p;
    };

    /**
     * @brief récupère la date d'envoie de la donnée
     * 
     * @return std::string 
     */
    std::string getDate() const
    {
      return m_date;
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
     * @brief récupère la valeur de la mesure
     * 
     * @return T 
     */
    T getValue() const
    {
      return m_value;
    };

    /**
     * @brief récupère l'unité de la donnée
     * 
     * @return std::string 
     */
    std::string getUnit() const
    {
      return m_unit;
    };
};

#endif