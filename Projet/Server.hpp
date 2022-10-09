#ifndef FICHIER_H
#define FICHIER_H

#include <iostream>

class server
{
private:
    int m_humidity;
    int m_light;
    int m_pression;
    int m_temperature;

public:
    server():m_humidity(), m_light(), m_pression(), m_temperature(){}
    server(const server& s): m_humidity(s.m_humidity), m_pression(s.m_pression), m_light(s.m_light), m_temperature(s.m_temperature){}
    ~server(){}

    void consolWrite();
    void fileWrite();
};

#endif //FICHIER_H