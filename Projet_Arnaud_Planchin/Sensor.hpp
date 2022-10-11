/**
 * @author Planchin Arnaud
 * @file Sensor.hpp
 * @date 03/10/2022
 * @brief Définition de la classe Sensor
 */

#ifndef SENSOR_H
#define SENSOR_H

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


class Sensor
{
public:

    int data; // Donnée du capteur

    /**
     * @brief Forme Canonique de Coplien de la classe Sensor
     */
    Sensor():data(){};
    Sensor(const Sensor& capteur):data(capteur.data){};
    ~Sensor(){};
    
    /**
     * @brief Récupère une valeur
     * @return une data de type int
     * @param - Aucun
     */
    int GetData();

    /**
     * @brief Génère une valeur aléatoire entre deux valeurs précisées en fonction de la donnée 
     * @return Un Sensor qui a comme attribut la data généré aleatoirement
     * @param - Aucun
     */
    Sensor aleaGenVal(int min, int max);

};


class Temperature: public Sensor{
public:
    /**
     * @brief Appelle la méthode aleaGenVal avec deux valeurs précisées pour le capteur utilisé
     * @return Un capteur de type Température
     * @param - Aucun
     */
    Sensor genAlea();
};

class Humidity: public Sensor{
public:
    /**
     * @brief Appelle la méthode aleaGenVal avec deux valeurs précisées pour le capteur utilisé
     * @return Un capteur de type Humidity
     * @param - Aucun
     */
    Sensor genAlea();
};

class Light: public Sensor{
public:
    /**
     * @brief Appelle la méthode aleaGenVal avec deux valeurs précisées pour le capteur utilisé
     * @return Un capteur de type Light
     * @param - Aucun
     */
    Sensor genAlea();
};

class Pression: public Sensor{
public:
    /**
     * @brief Appelle la méthode aleaGenVal avec deux valeurs précisées pour le capteur utilisé
     * @return Un capteur de type Pression
     * @param - Aucun
     */
    Sensor genAlea();
};

#endif // SERNSOR_H