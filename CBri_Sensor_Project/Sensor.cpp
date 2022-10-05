/**
 * @author BRICHET_Clement
 * @file Sensor.cpp
 * @date 23/09/2022
 * @brief 
 * */

#include "Sensor.hpp"

//Canonic functions
template <class Type> Sensor<Type>::Sensor():m_value(){}

template <class Type> Sensor<Type>::Sensor(const Sensor<Type>& sourceSensor):m_value(sourceSensor.m_value){}

template <class Type> Sensor<Type>::~Sensor(){}

template <class Type> Sensor<Type>& Sensor<Type>::operator=(const Sensor<Type>& sourceSensor)
{
    m_value = sourceSensor.m_value;
    return *this;
}

//Other function from the header
template <class Type> Type Sensor<Type>::getData(void)
{
    return this->m_value;
}