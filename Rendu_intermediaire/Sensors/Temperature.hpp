/**
 * @author Jules Ferlin
 * @file Temperature.hpp
 * @date 03/10/2022
 * @brief Fichier header contenant la définition des méthodes de la classe Temperature
 */

// Define Guard
#ifndef PROJET_AP4A_TEMPERATURE_HPP
#define PROJET_AP4A_TEMPERATURE_HPP

#include "../sensor.hpp"

/**
 * @class Temperature
 * @brief Classe Temperature héritant de la classe Sensor
 */
class Temperature : public Sensor<TYPE>
{
public:
  Temperature();
  Temperature(const Temperature& temp_p);
  virtual ~Temperature();
  Temperature& operator=(const Temperature& temp_p);
};

#endif //PROJET_AP4A_TEMPERATURE_HPP
