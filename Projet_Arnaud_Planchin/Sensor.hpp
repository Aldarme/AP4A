/**
 * @author Planchin Arnaud
 * @file Sensor.hpp
 * @date 03/10/2022
 * @brief Définition de la classe abstraite Sensor
 */

#ifndef SENSOR_H
#define SENSOR_H

template<typename T>
class Sensor
{

    friend class Light;
    friend class Humidity;
    friend class Temperature;
    friend class Pression;
    friend class Server;
    friend class Scheduler;

private:

    // Attributs d'un capteur
    T data;
    T min;
    T max;
    
public:

    /**
     * @brief Forme Canonique de Coplien de la classe Sensor
     */
    Sensor():data(),min(),max(){}
    virtual ~Sensor(){}
    Sensor(const Sensor& s):data(s.data),min(s.min),max(s.max){}
    
    /**
     * @brief Méthode virtuelle de récupération d'une valeur
     * @return Une data de type T
     */
    virtual T GetData() = 0;

    /**
     * @brief Méthode virtuelle de génération d'une valeur aléatoire entre deux valeurs: min, max 
     * @return Une data de type T
     * @param min - valeur minimum du capteur de type T
     * @param max - valeur maximum du capteur de type T
     */
    virtual T aleaGenVal(T min, T max) = 0;

};

#endif // SERNSOR_H