/**
* @author SZATKOWSKI Maxime
* @file Packet.hpp
* @date 02/10/2022
* @brief Fichier header contenant la définition des méthodes de la classe Packet
*/

#ifndef Packet_H
#define Packet_H

#include <iostream>

class Packet
{
    friend class Scheduler;
    friend class Server;

private:

    //attributs de la classe
    int m_press;
    float m_temp;
    bool m_light;
    float m_humid;

public:

    //Définition de la forme canonique
    Packet();
    Packet(const Packet& param_p);
    ~Packet() {}
    Packet operator=(const Packet&);
};

#endif //PACKET_H
