#ifndef Projet_AP4A_H
#define Projet_AP4A_H

#include <iostream>
#include <string>

class Sensor{
private :
    int valeur;
public :
    Sensor();
    Sensor(const int v);
    Sensor(const Sensor& s);
    ~Sensor();
};


#endif // Projet_AP4A_H