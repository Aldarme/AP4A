/**
 * @file Packet.hpp
 * @author Aurélien PETRA
 * @brief Permet regrouper des valeur de température, pression, lumière et pression au même endroit
 * @version 0.1
 * @date 2022-10-11
 *
 * @copyright Copyright (c) 2022
 *
 */

// Define guards
#ifndef PACKET_H
#define PACKET_H

/**
 * @class packet
 * @brief Permet regrouper des valeur de température, pression, lumière et pression au même endroit
 */
class packet
{
    friend class scheduler;
    friend class server;

private:
    float m_temp;
    int m_press;
    bool m_light;
    float m_humid;

public:
    packet() : m_temp(), m_press(), m_light(), m_humid() {}
    packet(const packet &param_p) : m_temp(param_p.m_temp), m_press(param_p.m_press), m_light(param_p.m_light), m_humid(param_p.m_humid) {}
    ~packet() {}
    packet &operator=(const packet &);
};

#endif // PACKET_H