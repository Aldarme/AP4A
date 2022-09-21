/**
 * @author RENON Emilien
 * @file MaClasse.hpp
 * @date 21/09/2022
 * @brief La classe Sensor permettra de créer les données des capteurs.
 */

//
// Define guards
#ifndef SENSOR_H
#define SENSOR_H
#include <iostream>
#include <cstdlib>
#include <string>

/**
 * @enum ESensor
 * @brief Enumération des 4 capteurs
 */
enum ESensor 
{
    e_temperature,
    e_humidity,
    e_light,
    e_pression,
};

/**
 * @class Sensor
 * @brief La classe Sensor permettra de créer les données des capteurs.
 */
class Sensor
{
public:
    // Definition de la forme canonique
    Sensor();
    Sensor(Sensor &s);
    ~Sensor();
    // ...

    /**
     * @brief Générer les valeurs des capteurs
     * @return int
     * @param rien
     */ 
    int aleaValue(ESensor param_name);
private:
    std::string m_name; /// Nom du capteur
    int m_value; /// Valeur du capteur
};








#endif // SERVER_H