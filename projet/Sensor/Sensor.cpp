//
// Created by rayan on 26/09/2022.
//
#include <random>
#include "Sensor.h"

template <class T>
Sensor<T>::Sensor() : T(){};

/**
 * @brief Construct a new Sensor Base:: Sensor Base object with default values
 */
SensorBase::SensorBase()
{
    this->m_data.sensorType = e_unknown_type;
    this->m_data.dataType = e_unknown_data;
};

/**
 * @brief Construct a new Sensor Base:: Sensor Base object with values
 * @param sT sensor type
 * @param dT sensor data type
 */
SensorBase::SensorBase(SensorType sT, DataType dT)
{
    this->m_data.sensorType = sT;
    this->m_data.dataType = dT;
    this->m_data.value = "";
};