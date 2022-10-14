/**
 * @author choulot_hugo
 * @file Humidity.hpp
 * @date 10/10/2022
 * @brief Classe Humidity
 */

//
// Define guards
#ifndef Projet_AP4A_HUMIDITY_H
#define Projet_AP4A_HUMIDITY_H

#include "Sensor.hpp"

/**
 * @class Humidity
 * @brief Permet de générer des objets capteurs d'humidité
 */
class Humidity : public Sensor<float> {

    public:

    //constructeur par défaut des capteurs Humidity
    Humidity()
    {

        this->m_name = ESensors::e_humidity;
        this->m_valeur = 0;

    }

    //constructeur par recopie des capteurs Humidity
    Humidity(const Humidity& h)
    {

        this->m_name = h.m_name;
        this->m_valeur = h.m_valeur;

    }

    //destructeur
    ~Humidity()
    {

    }

    /**
     * @brief permet de générer des valeurs aléatoires pour les capteurs de type Temperature
     * @return float
     * @param void
     */
    float aleaGenVal(){

        int low = 8; //valeur minimale d'humidité dans la cabine de l'avion
        int high = 20; //valeur maximale d'humidité dans la cabine de l'avion
        return low + static_cast<float>(rand()) * static_cast<float>(high - low) / RAND_MAX;

    }

};

#endif // Projet_AP4A_HUMIDITY_H