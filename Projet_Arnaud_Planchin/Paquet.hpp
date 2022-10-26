/**
 * @author Planchin Arnaud
 * @file Pacquet.hpp
 * @date 11/10/2022
 * @brief Défintion de la classe Paquet qui regroupe chaque donnée des Sensor
 */

#ifndef PACQUET_H
#define PACQUET_H

#include "Temperature.hpp"
#include "Humidity.hpp"
#include "Light.hpp"
#include "Pression.hpp"

class Paquet
{
    
    friend class Server;
    friend class Scheduler;

private:

    // Attributs d'un Paquet
    Temperature temperature;
    Humidity humidite;
    Light lumiere;
    Pression pression; 

public:

    /**
     * @brief Forme Canonique de Coplien de la classe Paquet
     */
    Paquet():temperature(),humidite(),lumiere(),pression(){}
    Paquet(const Paquet& pack):temperature(pack.temperature),humidite(pack.humidite),lumiere(pack.lumiere),pression(pack.pression){}
    virtual ~Paquet(){}
    Paquet operator=(const Paquet& pack);

};

#endif