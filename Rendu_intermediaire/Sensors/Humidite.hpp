/**
 * @author Jules Ferlin
 * @file Humidite.hpp
 * @date 03/10/2022
 * @brief Fichier header contenant la définition des méthodes de la classe Humidite
 */


#ifndef PROJET_AP4A_HUMIDITE_HPP
#define PROJET_AP4A_HUMIDITE_HPP

#include "../sensor.hpp"


/**
 * @class Humidite
 * @brief Classe humidite heritant de la classe Sensor
 */
class Humidite : public Sensor<TYPE>
{
public:
    // Forme canonique
    Humidite();
    Humidite(const Humidite& h_p);
    ~Humidite();
    Humidite& operator=(const Humidite& h_p);
};

#endif //PROJET_AP4A_HUMIDITE_HPP
