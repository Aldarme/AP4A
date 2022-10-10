/**
 * @author choulot_hugo
 * @file Sensor.hpp
 * @date 20/09/2022
 * @brief Classe mère des différents capteurs
 */

//
// Define guards
#ifndef Projet_AP4A_PRESSION_H
#define Projet_AP4A_PRESSION_H

#include <iostream>
#include <string>

#include "Sensor.hpp"

/**
 * @class Pression
 * @brief Permet de générer des objets capteurs de pression
 */
class Pression : public Sensor<int> {

    public :

    //constructeur par défaut des capteurs Pression
    Pression();

    //constructeur par recopie des capteurs Pression
    Pression(const Pression& p);

    //destructeur
    ~Pression();

    int aleaGenVal();

};

#endif // Projet_AP4A_PRESSION_H