/**
 * @author Jules Ferlin
 * @file Pression.hpp
 * @date 03/10/2022
 * @brief Fichier header contenant la définition des méthodes de la classe Pression
 */


// Define Guards
#ifndef PROJET_AP4A_PRESSION_HPP
#define PROJET_AP4A_PRESSION_HPP

#include "../sensor.hpp"


/**
 * @class Pression
 * @brief Classe Pression héritant de la classe Sensor
 */
class Pression : public Sensor<int>
{
public:
  // Forme Canonique
  Pression();
  Pression(const Pression& p_p);
  virtual ~Pression();
  Pression& operator=(const Pression& p_p);
};

#endif //PROJET_AP4A_PRESSION_HPP
