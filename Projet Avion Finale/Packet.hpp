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
    float m_temperature,m_humidity;
    int m_pression;
    bool m_light;
public:
    Packet()
    {
        this->m_temperature=0;
        this->m_pression=0;
        this->m_humidity=0;
        this->m_light=false;
    };
    ~Packet(){};
    float getTemperature();
    int getPression();
    float getHumidity();
    bool getLight();
    void setVal(float temperature_p,int pression_p,float humidity_p,bool light_p);
};

#endif