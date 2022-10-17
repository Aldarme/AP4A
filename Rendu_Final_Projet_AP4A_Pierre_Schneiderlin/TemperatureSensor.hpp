/**
 * @author Pierre Schneiderlin
 * @file TemperatureSensor.hpp
 * @date 11/10/2022
 * @brief header contenant la déclaration de la classe TemperatureSensor (classe fille de la classe Sensor) représentant un capteur de température
 */

#ifndef MACLASSE_TEMPERATURESENSOR_HPP
#define MACLASSE_TEMPERATURESENSOR_HPP

#include "main.hpp"

/**
 * @class TemperatureSensor
 * @brief Hérite de la classe Sensor, simule un capteur de température avec les attributs et méthodes de sa classe mère
 */
class TemperatureSensor : public Sensor<float>
{

public:

    /**
     * Constructeur par défaut
     */
    TemperatureSensor():Sensor(){setAllData(MINTEMP,MAXTEMP);}

    /**
     * Constructeur par recopie
     * @param t - l'objet de classe TemperatureSensor à recopier
     */
    TemperatureSensor(const TemperatureSensor& t) : Sensor<float>(t) {}

    /**
     * Destructeur
     */
    virtual ~TemperatureSensor()= default;

    /**
     * Opérateur d'affectation "=", appelant l'opérateur d'affectation de la classe mère Sensor
     * @param t - l'objet de classe Server dont on souhaite copier les attributs dans l'objet appelé
     * @return l'objet appelé modifié
     */
    TemperatureSensor& operator=(const TemperatureSensor& t){Sensor::operator=(t); return (*this);}
};

#endif //MACLASSE_TEMPERATURESENSOR_HPP
