//
// Created by rayan on 05/10/2022.
//

#ifndef PROJET_ENUM_H
#define PROJET_ENUM_H
#include <string>
#include <iostream>

// enum des noms des sensors
enum TypeSensor
{
    e_type,
    e_temperature,
    e_humidity,
    e_light,
    e_pressure
};

// type de donnees des data
enum TypeData
{
    e_data,
    e_float,
    e_int,
    e_bool
};

const std::string nomSensor[5]
        {
                "UNKNOWN_TYPE",
                "TEMPERATURE (\370C)",
                "HUMIDITE (%)  ",
                "LUMIERE (0/1) ",
                "PRESSION (kPa)"
        };


// structure avec type du sensor, type de donnee du sensor et sa valeur
typedef struct SensorData
{
    TypeSensor TypeSensor;
    TypeData TypeData;
    std::string value;
} SensorData;

#endif //PROJET_ENUM_H
