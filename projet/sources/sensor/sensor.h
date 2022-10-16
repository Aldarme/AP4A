//
// Created by rayan on 05/10/2022.
//
#ifndef PROJET_SENSOR_H
#define PROJET_SENSOR_H
#include  "../enum.h"
#include <cmath>

class MainSensor
{
protected:
    SensorData m_data;

    template <typename T>
    T aleaGenVal()
    {
        T min;
        T max;
        return aleaGenVal<T>(min, max);
    };


    template <typename T>
    T aleaGenVal(T min, T max)
    {
        if (min == max)
            return min;

        return min + std::fmod(rand(), max - min);
    };

public:
    MainSensor();
    MainSensor(TypeSensor sT, TypeData dT);
    ~MainSensor(){};
    virtual const SensorData &getData() = 0;
};

// template classe sensor qui hérite de mainsensor
template <class T>
class Sensor : public MainSensor
{
protected:
    T m_value;
public:
    Sensor<T>();
    Sensor<T>(TypeSensor sT, TypeData dT) : MainSensor(sT, dT), m_value(){
    };
    virtual ~Sensor(){};
    virtual const SensorData& getData() = 0;
};
#endif //PROJET_SENSOR_H
