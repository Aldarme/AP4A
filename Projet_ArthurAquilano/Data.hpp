/**
 * @author Arthur
 * @file Data.hpp
 * @date 03/10/22
 * @brief Déclaration des classes des data
 */

//DEFINE_GUARDS
#pragma once
#ifndef DATA_H
#define DATA_H

#include "Sensor.hpp"

class DataTemperature: public Sensor
{
public:
    int getVal();
};

class DataHumidity: public Sensor
{
public:
    int getVal();
};

class DataLight: public Sensor
{
public:
    int getVal();
};

class DataPressure: public Sensor
{
public:
    int getVal();
};

#endif //DATA.H