/*      author:TRABOULSI Rawan
       * PRESSURE
       * Créé le 19/09/2020          */
#ifndef PRESSURE_HPP
#define PRESSURE_HPP
#include "Sensor.hpp"
#include <string>

class Pressure:public Sensor{
//FORME CANONIQUE
public:
Pressure();//constructeur par defaut
Pressure(const Pressure & autre);//constructeur de recopie
Pressure &operator=(const Pressure &);//operateur d'affectation
virtual~Pressure();//destructeur


//Les Méthodes
int getPressuremax();
int getPressuremin();
int getPvalue();


private: 
int m_Pmax;
int m_Pmin;
int m_Pvalue;
};
#endif //PRESSURE_H
