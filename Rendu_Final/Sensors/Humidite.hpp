/**
 * @author Jules Ferlin
 * @file Humidite.hpp
 * @date 03/10/2022
 * @brief Fichier header contenant la définition des méthodes de la classe Humidite
 */


// Define Guards
#ifndef PROJET_AP4A_HUMIDITE_HPP
#define PROJET_AP4A_HUMIDITE_HPP

#include "../sensor.hpp"


/**
 * @class Humidite
 * @brief Classe humidité héritant de la classe Sensor
 */
class Humidite : public Sensor<float>
{
public:
  // Forme canonique
  Humidite();
  Humidite(const Humidite& h_p);
  ~Humidite();
  Humidite& operator=(const Humidite& h_p);
};

#endif //PROJET_AP4A_HUMIDITE_HPP
