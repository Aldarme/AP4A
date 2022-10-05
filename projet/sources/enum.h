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

// type de donnees des data (que float pour le rendu intermediaire)
enum TypeData
{
    e_data,
    e_float,
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
    float value;
} SensorData;

#endif //PROJET_ENUM_H
