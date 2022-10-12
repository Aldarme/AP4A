/**
 * @file Package.hpp
 * @author Loric Ravassard
 * @brief regroupe toutes les données dans un packet pour pouvoir les exploiter
 * @version 1
 * @date 2022-10-05
 */

#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>
#include <vector>
#include <iostream>

/**
 * @struct data 
 * @brief contient toutes les données utiles pour une mesure
 */
typedef struct
{
  std::string date;
  std::string name;
  int value;
  std::string unit;
} data; ///structure permettant de mettre toutes les données utiles pour un capteur

/**
 * @class Package
 * @brief regroupe toutes les données dans un packet pour pouvoir les exploiter
 * 
 */
class Package
{
  private:
    std::vector<data> m_allData;  ///stockage de toutes les données dans un vector
  public:
    Package() : m_allData(){};
    Package(const Package& other_p) : m_allData(other_p.m_allData){};
    virtual ~Package(){};
    Package& operator=(const Package& other_p);

    /**
     * @brief ajoute toutes les données d'un capteur au packet
     * 
     * @param date_p 
     * @param name_p 
     * @param val_p 
     * @param unit_p 
     */
    void addMeasure(std::string date_p, std::string name_p, int val_p, std::string unit_p);

    /**
     * @brief vide le vector de données
     * 
     */
    void clear();

    /**
     * @brief Get the Vector object
     * 
     * @return std::vector<data> 
     */
    std::vector<data> getVector() const;
};

#endif