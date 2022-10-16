//
// Created by rayan on 05/10/2022.
//
#include "sensor.h"
template <class T>
Sensor<T>::Sensor() : T(){

};

MainSensor::MainSensor()
{
    this->m_data.TypeSensor = e_type;
    this->m_data.TypeData = e_data;
};

MainSensor::MainSensor(TypeSensor sT, TypeData dT)
{
    this->m_data.TypeSensor = sT;
    this->m_data.TypeData = dT;
    this->m_data.value = "";
};