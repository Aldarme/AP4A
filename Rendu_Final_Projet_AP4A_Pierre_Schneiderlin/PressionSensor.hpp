/**
 * @author Pierre Schneiderlin
 * @file PressionSensor.hpp
 * @date 11/10/2022
 * @brief header contenant la déclaration de la classe PressionSensor (classe fille de la classe Sensor) représentant un capteur de pression
 */

#ifndef MACLASSE_PRESSIONSENSOR_HPP
#define MACLASSE_PRESSIONSENSOR_HPP

#include "main.hpp"
#include "Sensor.hpp"

/**
 * @class PressionSensor
 * @brief Hérite de la classe Sensor, simule un capteur de pression avec les attributs et méthodes de sa classe mère
 */
class PressionSensor : public Sensor<int>
{

public:

    /**
     * Constructeur par défaut
     */
    PressionSensor():Sensor(){setAllData(MINPRE,MAXPRE);}

    /**
     * Constructeur par recopie
     * @param p - l'objet de classe PressionSensor à recopier
     */
    PressionSensor(const PressionSensor& p) : Sensor<int>(p) {}

    /**
     * Destructeur
     */
    virtual ~PressionSensor()= default;

    /**
     * Opérateur d'affectation "=", appelant l'opérateur d'affectation de la classe mère Sensor
     * @param p - l'objet de classe Server dont on souhaite copier les attributs dans l'objet appelé
     * @return l'objet appelé modifié
     */
    PressionSensor& operator=(const PressionSensor& p){Sensor::operator=(p); return (*this);}
};

#endif //MACLASSE_PRESSIONSENSOR_HPP
