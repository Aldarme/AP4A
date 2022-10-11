/**
 * @author Planchin Arnaud
 * @file Pacquet.cpp
 * @date 11/10/2022
 * @brief Défintion de la classe Paquet qui regroupe chaque donnée des Sensor
 */

#ifndef PACQUET_H
#define PACQUET_H

#include "Sensor.hpp"
using namespace std;

class Paquet
{
public:

    Temperature temperature;
    Humidity humidite;
    Light lumiere;
    Pression pression; 

    /**
     * @brief Forme Canonique de Coplien de la classe Paquet
     */
    ~Paquet(){}
    Paquet():temperature(),humidite(),lumiere(),pression(){}
    Paquet(const Paquet& pack):temperature(pack.temperature),humidite(pack.humidite),lumiere(pack.lumiere),pression(pack.pression){}
    Paquet operator=(const Paquet& pack);

};

#endif