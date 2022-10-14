/**
 * @author choulot_hugo
 * @file Temperature.hpp
 * @date 10/10/2022
 * @brief Classe Temperature
 */

//
// Define guards
#ifndef Projet_AP4A_TEMPERATURE_H
#define Projet_AP4A_TEMPERATURE_H

#include "Sensor.hpp"

//déclaration template
//template <class T>

/**
 * @class Temperature
 * @brief Permet de générer des objets capteurs de température
 */
class Temperature : public Sensor<float> {

    public:

    //constructeur par défaut des capteurs Température
    Temperature()
    {

        this->m_name = ESensors::e_temperature;
        this->m_valeur = 0;

    }

    //constructeur par recopie des capteurs Température
    Temperature(const Temperature& t)
    {

        this->m_name = t.m_name;
        this->m_valeur = t.m_valeur;

    }

    //destructeur
    ~Temperature()
    {

    }

    /**
     * @brief permet de générer des valeurs aléatoires pour les capteurs de type Temperature
     * @return float
     * @param void
     */
    float aleaGenVal(){

        int low = 18; //valeur minimale de température dans la cabine de l'avion
        int high = 27; //valeur maximale de température dans la cabine de l'avion
        return low + static_cast<float>(rand()) * static_cast<float>(high - low) / RAND_MAX;

    }

};

#endif // Projet_AP4A_TEMPERATURE_H
