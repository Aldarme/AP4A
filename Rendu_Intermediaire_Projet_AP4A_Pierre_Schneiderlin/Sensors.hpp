/**
 * @author Pierre Schneiderlin
 * @file Sensor.hpp
 * @date 22/09/2022
 * @brief header contenant les déclarations de la classe Sensor (qui permet de générer des données pour simuler les relevés réalisés par un capteur),
 * et de ses classes filles (TemperatureSensor, HumiditySensor, LightSensor, PressionSensor) représentant des capteurs relevant différentes données
 */

#ifndef SENSOR_HPP
#define SENSOR_HPP

#include "main.hpp"

/**
 * @class Sensor
 * @brief Permet de générer des données pour simuler un capteur
 */
class Sensor {

private:

    float m_data; /// Contient la donnée générée par l'objet
    float m_dataMin; /// Contient la valeur minimale que peux prendre l'attribut m_data
    float m_dataMax; /// Contient la valeur maximale que peux prendre l'attribut m_data

    /**
     * Méthode permettant de générer une valeur aléatoire proche de celle actuelle de m_data tout en contrôlant
     * que la nouvelle valeur générée ne sorte pas de l'amplitude des valeurs autorisées
     */
    float aleaGenVal() const;

public:

    //////////////////////////////////// FORME CANONIQUE ////////////////////////////////////

    Sensor() : m_dataMin(), m_data(), m_dataMax() {}
    Sensor(float min, float max) : m_dataMin(min), m_dataMax(max), m_data() {}
    Sensor(const Sensor& p);
    ~Sensor(){};

    /////////////////////////////////////////////////////////////////////////////////////////

    /**
     * Méthode définissant la surcharge de l'opérateur d'affectation "="
     * @param s - l'objet de classe Sensor dont on souhaite copier les attributs dans l'objet appelé
     * @return l'objet appelé modifié
     */
    Sensor& operator=(const Sensor& s);

    /**
     * Méthode définissant la surcharge de l'opérateur de sortie <<
     * @param os - le flux de sortie par lequel on souhaite diriger l'objet s
     * @param s - l'objet de classe Sensor que l'on souhaite diriger vers le flux de sortie os
     * @return le flux de sortie dans lequel se trouve l'objet de classe Sensor tel qu'on souhaite qu'il soit affiché
     */
    friend std::ostream& operator<<(std::ostream& os, Sensor& s);

    /**
     * Méthode permettant d'accéder à l'attribut m_data de l'objet de classe Sensor
     * @return la valeur de l'attribut flottant m_data
     */
    float getData() const;

    /**
     * Méthode permettant d'accéder à l'attribut m_dataMin de l'objet de classe Sensor
     * @return la valeur de l'attribut flottant m_dataMin
     */
    float getDataMin() const;

    /**
     * Méthode permettant d'accéder à l'attribut m_dataMax de l'objet de classe Sensor
     * @return la valeur de l'attribut flottant m_dataMax
     */
    float getDataMax() const;

    /**
     * Méthode permettant d'affecter à l'attribut m_data de l'objet de classe Sensor une valeur aléatoire via
     * l'utilisation de la méthode aleaGenVal();
     */
    void setRandData();

    /**
     * Méthode permettant de modifier l'attribut m_dataMin de l'objet de classe Sensor
     * @param dataMin - la valeur flottante à affecter à l'attribut m_dataMin
     */
    void setDataMin(float dataMin);

    /**
     * Méthode permettant de modifier l'attribut m_dataMax de l'objet de classe Sensor
     * @param dataMax - la valeur flottante à affecter à l'attribut m_dataMax
     */
    void setDataMax(float dataMax);

    /**
     * Méthode permettant de modifier les attributs m_dataMin et m_dataMax de l'objet de classe Sensor
     * @param dataMin - la valeur flottante à affecter à l'attribut m_dataMin
     * @param dataMax - la valeur flottante à affecter à l'attribut m_dataMax
     */
    void setAllData(float dataMin, float dataMax);
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class TemperatureSensor
 * @brief Hérite de la classe Sensor, simule un capteur de température avec les attributs et méthodes de sa classe mère
 */
class TemperatureSensor : public Sensor
{

public:
    TemperatureSensor():Sensor(){setAllData(MINTEMP,MAXTEMP);}
    TemperatureSensor(float min, float max):Sensor(min, max){}
    TemperatureSensor(const TemperatureSensor& t) : Sensor(t) {}
    ~TemperatureSensor(){};
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class HumiditySensor
 * @brief Hérite de la classe Sensor, simule un capteur de température avec les attributs et méthodes de sa classe mère
 */
class HumiditySensor : public Sensor
{

public:
    HumiditySensor():Sensor(){setAllData(MINHUM,MAXHUM);}
    HumiditySensor(float min, float max):Sensor(min, max){}
    HumiditySensor(const HumiditySensor& h) : Sensor(h) {}
    ~HumiditySensor(){};
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class LightSensor
 * @brief Hérite de la classe Sensor, simule un capteur de lumière avec les attributs et méthodes de sa classe mère
 */
class LightSensor : public Sensor
{

public:
    LightSensor():Sensor(){setAllData(0,1);}
    LightSensor(float min, float max):Sensor(min, max){}
    LightSensor(const LightSensor& l) : Sensor(l) {}
    ~LightSensor(){};
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class PressionSensor
 * @brief Hérite de la classe Sensor, simule un capteur de pression avec les attributs et méthodes de sa classe mère
 */
class PressionSensor : public Sensor
{

public:
    PressionSensor():Sensor(){setAllData(MINPRE,MAXPRE);}
    PressionSensor(float min, float max):Sensor(min, max){}
    PressionSensor(const PressionSensor& p) : Sensor(p) {}
    ~PressionSensor(){};
};

#endif //SENSOR_HPP
