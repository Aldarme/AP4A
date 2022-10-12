#pragma once
//Sensor.hpp

#include "Server.hpp"
#include <iostream>
#include <fstream>

class Sensor
{

private:
    // les limites sont des entiers (cela permet l'utisation de (rand()%m_maxValue)+ m_minValue )


public:

    int m_value;
    int m_maxValue;
    int m_minValue;

    // Forme canonique de Coplien de la classe sensor
    Sensor(); //Constructeur par d�faut
    Sensor(const Sensor &sensor); //Constructeur par recopie
    ~Sensor(); //Destructeur
    Sensor& operator=(const Sensor& sensor); //Op�rateur d'affectation


    // Fonction qui permet de g�n�rer une valeur al�atoire pour notre sensor
    void aleaGenVal();

    int getValue();

    void setMinMax(int minValue_p, int maxValue_p);

    friend class Scheduler;
};

