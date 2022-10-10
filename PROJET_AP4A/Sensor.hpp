/**
 * @author RENON Emilien
 * @file Sensor.hpp
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
#include <fstream>

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
template <class T>
class Sensor
{
public:
    // Definition de la forme canonique
    Sensor(){};
    Sensor(const Sensor &param_sensor);
    ~Sensor(){};
    // ...

    /**
     * @brief Générer les valeurs des capteurs
     * @return int
     * @param rien
     */ 
    void aleaValue();

    /**
     * @brief Surcharge d'opérateur pour un cout
     * @return ostream&
     * @param ostream& et sensor&
     */ 
    template <class U>
    friend std::ostream& operator<<(std::ostream &param_os,const Sensor<U> &param_sensor);

    /**
     * @brief Surcharge d'opérateur pour une écriture dans un fichier
     * @return ofstream&
     * @param ofstream& et sensor&
     */ 
    template <class U>
    friend std::ofstream& operator<<(std::ofstream &param_of, const Sensor<U> &param_sensor);

protected:
    std::string m_name; /// Nom du capteur
    T m_value; /// Valeur du capteur
    ESensor m_sensor;   /// Enumeration pour pouvoir utiliser la fonction switch
};


#endif // SENSOR_H