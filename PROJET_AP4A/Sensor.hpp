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
class Sensor
{
public:
    // Definition de la forme canonique
    Sensor(){};
    Sensor(const Sensor &s);
    ~Sensor(){};
    // ...

    /**
     * @brief Générer les valeurs des capteurs
     * @return int
     * @param rien
     */ 
    void aleaValue();

    /**
     * @brief Obtenir la valeur du capteur
     * @return int
     * @param rien
     */ 
    int getValue();

    /**
     * @brief Surcharge d'opérateur pour un cout
     * @return ostream&
     * @param ostream& et sensor&
     */ 
    friend std::ostream & operator<<(std::ostream &param_os, const Sensor &param_sensor);

    /**
     * @brief Surcharge d'opérateur pour une écriture dans un fichier
     * @return ofstream&
     * @param ofstream& et sensor&
     */ 
    friend std::ofstream &operator<<(std::ofstream &param_of, const Sensor &param_sensor);

protected:
    std::string m_name; /// Nom du capteur
    int m_value; /// Valeur du capteur
    ESensor m_sensor;   /// Enumeration pour pouvoir utiliser la fonction switch
};

/**
 * @class Temperature
 * @brief La classe Temperature simule le fonctionnement du capteur de température
 */
class Temperature : public Sensor
{
public:
    // Definition de la forme canonique
    Temperature();
    Temperature(const Temperature &t);
    ~Temperature(){};
    // ...
       
};

/**
 * @class Humidity
 * @brief La classe Humidity simule le fonctionnement du capteur d'humidité
 */
class Humidity : public Sensor
{
public:
    // Definition de la forme canonique
    Humidity();
    Humidity(const Humidity &h);
    ~Humidity(){};
    // ...

};

/**
 * @class Light
 * @brief La classe Light simule le fonctionnement du capteur de lumière
 */
class Light : public Sensor
{
public:
    // Definition de la forme canonique
    Light();
    Light(const Light &l);
    ~Light(){};
    // ...
      
};

/**
 * @class Pression
 * @brief La classe Pression simule le fonctionnement du capteur de pression
 */
class Pression : public Sensor
{
public:
    // Definition de la forme canonique
    Pression();
    Pression(const Pression &p);
    ~Pression(){};
    // ...
      
};





#endif // SENSOR_H