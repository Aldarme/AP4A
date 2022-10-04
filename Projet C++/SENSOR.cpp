#ifndef SENSOR_CPP
#define SENSOR_CPP

#include <iostream>
#include"SENSOR.h"

using namespace std;

template <class T> T Sensor<T>::getData()
{
    return this->value;
}

template <class T> T Sensor<T>::aleaGenVal()
{
    int p_int;
    int t_float;
    int h_float;
    int l_bool;

    srand(time(NULL));

    switch (this->type)
    {
    case "pression":
    {
        p_int = (rand()%10);
        return p_int;
    }break;
    case "light":
    {
        l_bool = (rand() % 10+10);
        return l_bool;
    }break;
    case "humidity":
    {
        h_float = (rand() % 10) + 20;
        return h_float;
    }break;
    case "temperature":
    {
        t_float = (rand() % 10) + 30;
        return t_float;
    }break;
    }
}

#endif