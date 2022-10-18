/*      author:TRABOULSI Rawan
       * PRESSURE
       * Créé le 19/09/2020          */
#ifndef PRESSURE_HPP
#define PRESSURE_HPP
#include "Sensor.hpp"
#include <string>

class Pressure:public Sensor<int>{
       //les attributs de type int
private: 
       int m_Pmax;
       int m_Pmin;
       int m_Pvalue;
       

public:
Pressure();//constructeur par defaut
Pressure(const Pressure & autre);//constructeur de recopie
Pressure &operator=(const Pressure &);//operateur d'affectation
virtual~Pressure();//destructeur

//Les Méthodes de type int
int getPressuremax();
int getPressuremin();
int getPvalue();



};
#endif //PRESSURE_H
