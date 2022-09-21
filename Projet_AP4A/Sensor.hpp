#ifndef Projet_AP4A_H
#define Projet_AP4A_H

#include <iostream>
#include <string>

enum ESensors {
    e_temperature,
    e_humidity,
    e_light,
    e_pression
};

class Sensor{
private :
    int m_valeur;
    ESensors m_name;
public :
    Sensor();
    Sensor(const ESensors param_name);
    Sensor(const Sensor& s);
    ~Sensor();

    Sensor& operator=(const Sensor& s);

    int aleaGenVal(const ESensors name);
};


#endif // Projet_AP4A_H