/**
 * @author Pierre Schneiderlin
 * @file LightSensor.hpp
 * @date 11/10/2022
 * @brief header contenant la déclaration de la classe LightSensor (classe fille de la classe Sensor) représentant un capteur de lumière
 */

#ifndef MACLASSE_LIGHTSENSOR_HPP
#define MACLASSE_LIGHTSENSOR_HPP

#include "main.hpp"
#include "Sensor.hpp"
/**
 * @class LightSensor
 * @brief Hérite de la classe Sensor, simule un capteur de lumière avec les attributs et méthodes de sa classe mère
 */
class LightSensor : public Sensor<bool>
{

public:

    /**
     * Constructeur par défaut
     */
    LightSensor():Sensor(){setAllData(true,false);}

    /**
     * Constructeur par recopie
     * @param l - l'objet de classe LightSensor à recopier
     */
    LightSensor(const LightSensor& l) : Sensor<bool>(l) {}

    /**
     * Destructeur
     */
    virtual ~LightSensor()= default;;

    /**
     * Opérateur d'affectation "=", appelant l'opérateur d'affectation de la classe mère Sensor
     * @param l - l'objet de classe Server dont on souhaite copier les attributs dans l'objet appelé
     * @return l'objet appelé modifié
     */
    LightSensor& operator=(const LightSensor& l){Sensor::operator=(l); return (*this);}
};

#endif //MACLASSE_LIGHTSENSOR_HPP
