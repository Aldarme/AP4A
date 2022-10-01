/**
 * @author Jules Ferlin
 * @file Sensor.hpp
 * @date
 * @brief
 */

#ifndef PROJET_AP4A_Sensor_HPP
#define PROJET_AP4A_Sensor_HPP
#include <cstdlib>
#include <ctime>
#include <iostream>

template<class T>
class Sensor
{
protected:
    T m_minValue, m_maxValue;
public:
    Sensor<T>();
    Sensor<T>(const Sensor<T>& param_Sensor);
    ~Sensor<T>();
    Sensor<T>& operator=(const Sensor<T>& param_Sensor);
    virtual T getData();
    T aleaGenVal(float param_minVal, float param_maxVal);
};

template<typename T>
Sensor<T>::Sensor()
{
    this->m_minValue = 0;
    this->m_maxValue = 1;
}

template<typename T>
Sensor<T>::Sensor(const Sensor<T>& param_Sensor): m_minValue(this->m_minValue), m_maxValue(this->m_maxValue) {}

template<typename T>
Sensor<T>& Sensor<T>::operator=(const Sensor<T>& param_Sensor) {
    this->m_minValue = param_Sensor.m_minValue;
    this->m_maxValue = param_Sensor.m_maxValue;
    return *this;
}

template<typename T>
T Sensor<T>::getData()
{
    return this->aleaGenVal(this->m_minValue, this->m_maxValue);
}

template<typename T>
T Sensor<T>::aleaGenVal(float param_minVal, float param_maxVal)
{
    return (param_minVal + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(param_maxVal-param_minVal))));
}


#endif //PROJET_AP4A_Sensor_HPP
