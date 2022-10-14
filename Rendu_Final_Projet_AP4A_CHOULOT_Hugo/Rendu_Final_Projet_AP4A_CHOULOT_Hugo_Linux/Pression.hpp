/**
 * @author choulot_hugo
 * @file Pression.hpp
 * @date 10/10/2022
 * @brief Classe Pression
 */

//
// Define guards
#ifndef Projet_AP4A_PRESSION_H
#define Projet_AP4A_PRESSION_H

#include "Sensor.cpp"

/**
 * @class Pression
 * @brief Permet de générer des objets capteurs de pression
 */
class Pression : public Sensor<int> {

    public :

    //constructeur par défaut des capteurs Pression
    Pression()
    {

        this->m_name = ESensors::e_pression;
        this->m_valeur = 0;

    }

    //constructeur par recopie des capteurs Pression
    Pression(const Pression& p)
    {

        this->m_name = p.m_name;
        this->m_valeur = p.m_valeur;

    }

    //destructeur
    ~Pression()
    {

    }

    /**
     * @brief permet de générer des valeurs aléatoires pour les capteurs de type Pression
     * @return int
     * @param void
     */
    int aleaGenVal()
    {

        return rand() % 100 + 700; //pression dans la cabine de l'avion comprise entre 700 et 800 hPa

    }

};

#endif // Projet_AP4A_PRESSION_H