/**
 * @author Planchin Arnaud
 * @file Pacquet.cpp
 * @date 11/10/2022
 * @brief Défintion de l'opérator= de la classe Pacquet
 */

#include "Paquet.hpp"

Paquet Paquet::operator=(const Paquet& pack){
    temperature = pack.temperature;
    humidite = pack.humidite;
    lumiere = pack.lumiere;
    pression = pack.pression;
    return *this;
}