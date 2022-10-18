/**
 * @author YUHUIFEI
 * @file SENSOR.cpp
 * @date 15/10/2022
 * @brief La classe Sensor permettra de cr¨¦er les donn¨¦es des capteurs.
 */
#ifndef SENSOR_CPP
#define SENSOR_CPP

#include <iostream>
#include"SENSOR.h"

using namespace std;

template <class T> T Sensor<T>::getData()
{
    return this->value;
}


//Obtenir des donn¨¦es al¨¦atoires
template <class T> T Sensor<T>::aleaGenVal()
{
    srand(time(NULL));

    switch (this->type)
    {
    case "pression":
    {
        this->m_value = (rand()%8+2);
    }break;
    case "light":
    {
        this->m_value = ((rand() % 2+1)/2);
    }break;
    case "humidity":
    {
        this->m_value = ((rand() % 1000) + 1000)/100;
    }break;
    case "temperature":
    {
        this->m_value = ((rand() % 1000) + 2000)/100;
    }break;
    }
}

//Surcharge du symbole "<<"
template <class T>
ostream& operator<<(ostream& param_os, const Sensor<T>& param_sensor)
{
    param_os << param_sensor.m_name << " : " << param_sensor.m_value << endl;
    return param_os;
}

//Surcharge du symbole "<<"
template <class T>
ofstream& operator<<(ofstream& param_of, const Sensor<T>& param_sensor)
{
    param_of << param_sensor.m_name << ";" << param_sensor.m_value << ";";
    return param_of;
}

#endif