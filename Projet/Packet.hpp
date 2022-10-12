/**
 * @author Erhart Eliott
 * @file Packet.hpp
 * @date 10/10/2022
 * @brief Définition de la classe Packet
 */

//DEFINE GUARDS
#ifndef PACKET_H
#define PACKET_H

#include "Sensor.hpp"

/** 
 * @class Packet
 * @brief Implémentation classe Packet  
 */

class Packet
{
public:
        /// @brief Déclaration de la forme canonique de Coplien
        Packet ():H(),L(),P(),T(){}; // Constructeur par défaut
        Packet (const Packet& a):H(a.H),L(a.L),P(a.P),T(a.T){}; // Constructeur par recopie
        ~Packet (){}; // Destructeur

        /// @brief Instanciation des différents capteurs
        Humidity H;
        Light L;
        Pressure P;
        Temperature T;
};

#endif // PACKET_H