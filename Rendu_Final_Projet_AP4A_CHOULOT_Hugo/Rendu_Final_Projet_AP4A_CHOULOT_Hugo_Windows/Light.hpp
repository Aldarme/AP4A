/**
 * @author choulot_hugo
 * @file LIght.hpp
 * @date 10/10/2022
 * @brief Classe Light
 */

//
// Define guards
#ifndef Projet_AP4A_LIGHT_H
#define Projet_AP4A_LIGHT_H

#include "Sensor.hpp"

/**
 * @class Light
 * @brief Permet de générer des objets capteurs de lumière
 */
class Light : public Sensor<bool> {

    public :

    //constructeur par défaut des capteurs Light
    Light()
    {

        this->m_name = ESensors::e_light;
        this->m_valeur = 0;

    }

    //constructeur par recopie des capteurs Light
    Light(const Light& l)
    {

        this->m_name = l.m_name;
        this->m_valeur = l.m_valeur;

    }

    //destructeur
    ~Light()
    {

    }

    /**
     * @brief permet de générer des valeurs aléatoires pour les capteurs de type Temperature
     * @return bool
     * @param void
     */
    bool aleaGenVal(){

        int m_light= rand() % 2;

        if(m_light == 1){

        return true;

        }
        else
        {

        return false;
        }
    }

};

#endif // Projet_AP4A_LIGHT_H