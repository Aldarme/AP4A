/**
 * @author Pierre Schneiderlin
 * @file HumiditySensor.hpp
 * @date 11/10/2022
 * @brief header contenant la déclaration de la classe HumiditySensor (classe fille de la classe Sensor) représentant un capteur d'humidité
 */

#ifndef MACLASSE_HUMIDITYSENSOR_HPP
#define MACLASSE_HUMIDITYSENSOR_HPP

#include "main.hpp"
#include "Sensor.hpp"

/**
 * @class HumiditySensor
 * @brief Hérite de la classe Sensor, simule un capteur de température avec les attributs et méthodes de sa classe mère
 */
class HumiditySensor : public Sensor<float>
{

public:

    /**
     * Constructeur par défaut
     */
    HumiditySensor():Sensor(){setAllData(MINHUM,MAXHUM);}

    /**
     * Constructeur par recopie
     * @param h - l'objet de classe HumiditySensor à recopier
     */
    HumiditySensor(const HumiditySensor& h) : Sensor<float>(h) {}

    /**
     * Destructeur
     */
    virtual ~HumiditySensor()= default;

    /**
     * Opérateur d'affectation "=", appelant l'opérateur d'affectation de la classe mère Sensor
     * @param h - l'objet de classe Server dont on souhaite copier les attributs dans l'objet appelé
     * @return l'objet appelé modifié
     */
    HumiditySensor& operator=(const HumiditySensor& h){Sensor::operator=(h); return (*this);}
};


#endif //MACLASSE_HUMIDITYSENSOR_HPP
