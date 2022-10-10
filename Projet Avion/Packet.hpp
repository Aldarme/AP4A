/**
 *  @author BIN ADNAN Muhammad Izzat Affandi
 *  @file Packet.hpp
 *  @date 6/10/2022
 *  @brief This file contains declarations of the class "Packet" which will contain all sensors' data
 */

#ifndef PACKET_H
#define PACKET_H

class Packet
{
private:
    int m_temperature,m_pression,m_humidity,m_light;
public:
    Packet()
    {
        this->m_temperature=0;
        this->m_pression=0;
        this->m_humidity=0;
        this->m_light=0;
    };
    ~Packet(){};
    int getTemperature();
    int getPression();
    int getHumidity();
    int getLight();
    void setVal(int temperature_p,int pression_p,int humidity_p,int light_p);
};

#endif