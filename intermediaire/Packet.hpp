/**
 * @author Céliane ALLAIRE
 * @file Packet.hpp
 * @date 28/09/2022
 * @brief 
 * */

//
//Define guards
#ifndef PACKET_H
#define PACKET_H


/**
 * @class Sensor
 * @brief classe packet. Cette classe est conçue pour stocker la globalité des résultats des différents Sensors. Nous permettant ainsi d'envoyer uniquement cette classe au Sever
 */
class Packet
{
private:
    int m_humid; 
    int m_light;
    int m_press;
    int m_temp;
public:
// Definition de la forme canonique
    Packet():m_humid(), m_light(), m_press(), m_temp(){}; //Constructeur pas défaut
    Packet(const Packet& param_s):m_humid(param_s.m_humid), m_light(param_s.m_light), m_press(param_s.m_press), m_temp(m_temp){}; //Constructeur par recopie
    Packet& operator=(const Packet& param_s); //Opérateur d'affectation
    ~Packet(); //Destructeur

    void setData(const int humid_p, const int light_p, const int press_p, const int temp_p); //Déclaration des valeurs des différents capteurs  
};


#endif  // PACKET_H